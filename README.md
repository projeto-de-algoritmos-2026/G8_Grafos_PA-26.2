# G8_Grafos_PA-26.2

*Módulo da disciplina*: Grafos
--- 
## Alunos
| Matrícula | Aluno |
|---|---|
| 251012313 | Luis Gustavo Ferreira Nunes |
| 251013624  | Mateus Alves Araujo |
---
# O Caminho do Cavalo - Algoritmos de Busca em Grafos ♞

Projeto desenvolvido para a disciplina de Grafos, com o objetivo de aplicar algoritmos de busca de caminhos mínimos (Pathfinding) em um cenário interativo e visual. 

O programa simula o movimento de um Cavalo de xadrez (que se move em "L") em um tabuleiro 8x8. O tabuleiro é modelado matematicamente como um **Grafo**, onde cada casa é um vértice e cada movimento válido do cavalo é uma aresta.

## --- Algoritmos Utilizados ---

*   **Algoritmo de Dijkstra:** Calcula a rota garantindo o menor custo total, explorando os nós de forma uniforme a partir do ponto de origem.
*   **Algoritmo A*:** Otimiza a busca utilizando a heurística da distância euclidiana para "guiar" a busca diretamente na direção do destino, processando menos vértices de forma inteligente.

## --- Tecnologias e Dependências ---

*   **Linguagem:** C++17
*   **Interface Gráfica:** [Raylib 5.0](https://www.raylib.com/) (baixada e linkada automaticamente via CMake)
*   **Build System:** CMake (>= 3.5)
*   **Compilador:** GCC/G++ (Linux) ou MinGW (Windows)

## --- Como Compilar e Rodar (Linux) ---

O projeto utiliza o CMake para gerenciar dependências. Não é necessário instalar a Raylib no sistema operacional, o script fará o download e a configuração automaticamente.

Clone o repositório e execute os comandos abaixo no terminal:

```bash
# 1. Crie uma pasta para os arquivos de compilação e entre nela
mkdir build && cd build

# 2. Gere os arquivos de configuração do CMake
cmake ..

# 3. Compile o executável
make

# 4. Execute o programa
./CavaloRaylib
```

## --- Controles da Interface ---

* **Botão Esquerdo do Mouse:**
* 1º Clique: Define a casa de **Início** (com a peça do Cavalo).
* 2º Clique: Define a casa de **Destino** (Vermelho), dispara o algoritmo A* e inicia a animação do trajeto.


* **Botão do Meio do Mouse:** Adiciona ou remove **Obstáculos** (bloqueios com peças pretas) dinamicamente no tabuleiro.
* **Botão Direito do Mouse:** Limpa o tabuleiro para realizar uma nova busca.

## --- Estrutura do Projeto ---

```text
├── assets/               # Planilhas de sprites (Pixel Art)
├── src/
│   ├── grafo.h           # Estruturas do grafo, heurística e motor do A*
│   └── main.cpp          # Código principal, animação, loop e interface Raylib
├── CMakeLists.txt        # Configuração do CMake e dependências
└── README.md             # Documentação

```

## --- Créditos de Assets ---

* As peças de xadrez em pixel art utilizadas na interface gráfica foram criadas por **Dani Maccari** e estão disponíveis no itch.io: [Pixel Chess por Dani Maccari](https://dani-maccari.itch.io/pixel-chess).

---

## Vídeo de apresentação

---