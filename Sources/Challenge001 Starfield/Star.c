#include "Star.h"

#include <Helper/Math.h>
#include <Helper/Random.h>
#include <raylib.h>

void Star_init(Star* star) {
  star->x = RandomFloatBetween(-GetScreenWidth(), GetScreenWidth());
  star->y = RandomFloatBetween(-GetScreenHeight(), GetScreenHeight());
  star->z = RandomFloatBetween(0, GetScreenWidth());
}

void Star_update(Star* star) {
  star->z -= 10 * GetFrameTime() * 60;
  if (star->z < 1) {
    star->x = RandomFloatBetween(-GetScreenWidth(), GetScreenWidth());
    star->y = RandomFloatBetween(-GetScreenHeight(), GetScreenHeight());
    star->z = GetScreenWidth();
  }
}

void Star_show(Star* star) {
  float sx = Map(star->x / star->z, 0, 1, 0, GetScreenWidth());
  float sy = Map(star->y / star->z, 0, 1, 0, GetScreenWidth());
  float r = Map(star->z, 0, GetScreenWidth(), 8, 0);
  DrawCircle(sx + (float)GetScreenWidth() / 2,
             sy + (float)GetScreenHeight() / 2, r, WHITE);
}
