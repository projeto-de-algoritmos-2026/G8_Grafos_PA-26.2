#include "raylib.h"
#include <vector>

const int BOARD_SIZE = 8;
const int TILE_SIZE = 80;
const int SCREEN_SIZE = BOARD_SIZE * TILE_SIZE;

int main() {
    InitWindow(SCREEN_SIZE, SCREEN_SIZE, "Caminho do Cavalo - Dijkstra/A*");
    SetTargetFPS(60);

    int startX = -1, startY = -1;
    int targetX = -1, targetY = -1;

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            int gridX = GetMouseX() / TILE_SIZE;
            int gridY = GetMouseY() / TILE_SIZE;

            if (startX == -1) {
                startX = gridX;
                startY = gridY;
            } else if (targetX == -1) {
                targetX = gridX;
                targetY = gridY;

                // TODO: A chamada do Algoritmo ficará aqui!!
                // Exemplo: std::vector<Coordenada> caminho = executarDijkstra(startX, startY, targetX, targetY);
            }
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            startX = -1; startY = -1;
            targetX = -1; targetY = -1;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int y = 0; y < BOARD_SIZE; y++) {
            for (int x = 0; x < BOARD_SIZE; x++) {
                Color tileColor = ((x + y) % 2 == 0) ? RAYWHITE : LIGHTGRAY;
                DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, tileColor);
                DrawRectangleLines(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, DARKGRAY);
            }
        }

        if (startX != -1) {
            DrawRectangle(startX * TILE_SIZE, startY * TILE_SIZE, TILE_SIZE, TILE_SIZE, GREEN);
        }
        if (targetX != -1) {
            DrawRectangle(targetX * TILE_SIZE, targetY * TILE_SIZE, TILE_SIZE, TILE_SIZE, RED);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}