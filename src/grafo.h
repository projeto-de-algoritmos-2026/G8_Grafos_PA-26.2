#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>

struct Posicao {
    int x, y;

    bool operator == (const Posicao& outra) const {
        return x == outra.x && y == outra.y;
    }
    bool operator < (const Posicao& outra) const {
        if (x != outra.x) return x < outra.x;
        return y < outra.y;
    }
};

// Função Heurística: Distância Euclidiana para guiar o A* em direção ao destino
inline double calcularHeuristica(Posicao atual, Posicao destino) {
    return std::sqrt(std::pow(atual.x - destino.x, 2) + std::pow(atual.y - destino.y, 2));
}

struct NoAStar {
    Posicao pos;
    double custoG; // Custo real acumulado desde a origem
    double custoF; // Custo total estimado (G + Heurística)

    // O topo da fila de prioridade deve ser sempre o de MENOR custo F
    bool operator > (const NoAStar& outro) const {
        return custoF > outro.custoF;
    }
};

inline std::vector<Posicao> encontrarCaminhoCavalo(Posicao inicio, Posicao destino, const std::vector<Posicao>& obstaculos) {
    int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

    std::priority_queue<NoAStar, std::vector<NoAStar>, std::greater<NoAStar>> fila;

    std::map<Posicao, double> custosG;
    std::map<Posicao, Posicao> pais;

    double hInicial = calcularHeuristica(inicio, destino);
    fila.push({inicio, 0.0, hInicial});
    custosG[inicio] = 0.0;

    while (!fila.empty()) {
        NoAStar atual = fila.top();
        fila.pop();

        if (atual.pos == destino) break;

        for (int i = 0; i < 8; i++) {
            Posicao vizinho = {atual.pos.x + dx[i], atual.pos.y + dy[i]};

            // Valida se o vizinho está dentro do tabuleiro 8x8
            if (vizinho.x >= 0 && vizinho.x < 8 && vizinho.y >= 0 && vizinho.y < 8) {
                
                // Se for um obstáculo, ignora
                if (std::find(obstaculos.begin(), obstaculos.end(), vizinho) != obstaculos.end()) {
                    continue;
                }

                double novoCustoG = custosG[atual.pos] + 1.0;

                // Se o vizinho ainda não foi visitado ou encontramos um caminho mais curto até ele
                if (custosG.find(vizinho) == custosG.end() || novoCustoG < custosG[vizinho]) {
                    custosG[vizinho] = novoCustoG;
                    double h = calcularHeuristica(vizinho, destino);
                    double novoCustoF = novoCustoG + h;

                    pais[vizinho] = atual.pos;
                    fila.push({vizinho, novoCustoG, novoCustoF});
                }
            }
        }
    }

    // Reconstrução do caminho de trás para frente
    std::vector<Posicao> caminho;
    Posicao passo = destino;

    if (pais.find(passo) == pais.end() && !(inicio == destino)) return caminho;

    while (!(passo == inicio)) {
        caminho.push_back(passo);
        passo = pais[passo];
    }
    caminho.push_back(inicio);

    std::reverse(caminho.begin(), caminho.end());

    return caminho;
}

#endif