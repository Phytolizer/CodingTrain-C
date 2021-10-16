#include <Helper/Random.h>
#include <math.h>
#include <raylib.h>

#include "Snake.h"

static void PickLocation(Vector2* food);

int main() {
  InitWindow(600, 600, "Snake");

  Snake s;
  Snake_init(&s);
  SetTargetFPS(10);
  Vector2 food;
  PickLocation(&food);

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_UP)) {
      Snake_dir(&s, (Vector2){0, -1});
    }
    if (IsKeyPressed(KEY_DOWN)) {
      Snake_dir(&s, (Vector2){0, 1});
    }
    if (IsKeyPressed(KEY_LEFT)) {
      Snake_dir(&s, (Vector2){-1, 0});
    }
    if (IsKeyPressed(KEY_RIGHT)) {
      Snake_dir(&s, (Vector2){1, 0});
    }

    BeginDrawing();
    ClearBackground(CLITERAL(Color){51, 51, 51, 255});

    if (Snake_eat(&s, food)) {
      PickLocation(&food);
    }
    Snake_death(&s);
    Snake_update(&s);
    Snake_show(&s);

    DrawRectangle(food.x, food.y, SCL, SCL, CLITERAL(Color){255, 0, 100, 255});

    EndDrawing();
  }

  Snake_deinit(&s);
  CloseWindow();
  return 0;
}

static void PickLocation(Vector2* food) {
  int cols = GetScreenWidth() / SCL;
  int rows = GetScreenHeight() / SCL;
  food->x = floorf(RandomFloatBetween(0, cols));
  food->y = floorf(RandomFloatBetween(0, rows));
  food->x *= SCL;
  food->y *= SCL;
}
