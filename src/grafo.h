#include <vector>
#include <queue>
#include <map>
#include <algorithm>

struct Posicao {
    int x, y;

    bool operator == (const Posicao& outra) const {
        return x == outra.x &&  y == outra.y;
    }
    bool operator < (const Posicao& outra) const {
        if (x != outra.x) return x < outra.x;
        return y < outra.y;
    }
};

struct No {
    Posicao pos;
    int custo;

    bool operator > (const No& outro) const {
        return custo > outro.custo;
    }
};

std::vector<Posicao> encontrarCaminhoCavalo(Posicao inicio, Posicao destino, const std::vector<Posicao>& obstaculos) {
    int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

    std::priority_queue<No, std::vector<No>, std::greater<No>> fila;

    std::map<Posicao, int> custos;
    std::map<Posicao, Posicao> pais;

    fila.push({inicio, 0});
    custos[inicio] = 0;

    while(!fila.empty()) {
        No atual = fila.top();
        fila.pop();

        if (atual.pos == destino) break;

        for (int i = 0; i < 8; i++) {
            Posicao vizinho = {atual.pos.x + dx[i], atual.pos.y + dy[i]};

            if (vizinho.x >= 0 && vizinho.x < 8 && vizinho.y >= 0 && vizinho.y < 8) {
                if (std::find(obstaculos.begin(), obstaculos.end(), vizinho) != obstaculos.end()) {
                    continue;
                }
                
                int novoCusto = custos[atual.pos] + 1;
                   
                if (custos.find(vizinho) == custos.end() || novoCusto < custos[vizinho]) {
                    custos[vizinho] = novoCusto;
                    pais[vizinho] = atual.pos;
                    fila.push({vizinho, novoCusto});
                }
            }
        }
    }

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