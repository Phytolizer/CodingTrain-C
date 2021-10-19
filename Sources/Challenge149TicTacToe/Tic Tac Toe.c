#include <raylib.h>

int main() {
  char board[3][3] = {
      {'O', 'X', 'O'},
      {'O', 'X', 'X'},
      {'O', 'O', 'X'},
  };
  char player1 = 'X';
  char player2 = 'O';

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  InitWindow(400, 400, "Tic Tac Toe");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(CLITERAL(Color){220, 220, 220, 255});

    int w = GetScreenWidth() / 3;
    int h = GetScreenHeight() / 3;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        int x = w * i + w / 2;
        int y = h * j + w / 2;
        if (board[i][j] == player2) {
          DrawCircleLines(x, y, (float)w / 2, BLACK);
        } else if (board[i][j] == player1) {
          int xr = w / 2;
          DrawLine(x - xr, y - xr, x + xr, y + xr, BLACK);
          DrawLine(x + xr, y - xr, x - xr, y + xr, BLACK);
        }
      }
    }
    EndDrawing();
  }

  CloseWindow();
}
