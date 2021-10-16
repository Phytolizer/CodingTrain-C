#include <raylib.h>

int main() {
  InitWindow(400, 400, "Starfield");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
