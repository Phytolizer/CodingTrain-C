#include <raylib.h>
#include <stddef.h>

#include "Drop.h"

int main() {
  InitWindow(640, 360, "Purple Rain");

  Drop drops[500];
  for (size_t i = 0; i < sizeof(drops) / sizeof(Drop); ++i) {
    Drop_init(&drops[i]);
  }

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(CLITERAL(Color){230, 230, 250, 255});
    for (size_t i = 0; i < sizeof(drops) / sizeof(Drop); ++i) {
      Drop_fall(&drops[i]);
      Drop_show(&drops[i]);
    }
    EndDrawing();
  }

  CloseWindow();
}
