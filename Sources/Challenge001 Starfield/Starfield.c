#include <raylib.h>
#include <stddef.h>

#include "Star.h"

int main() {
  Star stars[800];

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  InitWindow(800, 800, "Starfield");

  for (size_t i = 0; i < sizeof(stars) / sizeof(Star); ++i) {
    Star_init(&stars[i]);
  }

  while (!WindowShouldClose()) {
    for (size_t i = 0; i < sizeof(stars) / sizeof(Star); ++i) {
      Star_update(&stars[i]);
    }

    BeginDrawing();
    ClearBackground(BLACK);
    for (size_t i = 0; i < sizeof(stars) / sizeof(Star); ++i) {
      Star_show(&stars[i]);
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
