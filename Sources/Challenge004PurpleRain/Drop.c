#include "Drop.h"

#include <Helper/Math.h>
#include <Helper/Random.h>
#include <raylib.h>

void Drop_init(Drop* d) {
  d->x = RandomFloatBetween(0, GetScreenWidth());
  d->y = RandomFloatBetween(-500, -50);
  d->z = RandomFloatBetween(0, 20);
  d->len = Map(d->z, 0, 20, 10, 20);
  d->yspeed = Map(d->z, 0, 20, 1, 20);
}

void Drop_fall(Drop* d) {
  d->y += d->yspeed * GetFrameTime() * 60;
  float grav = Map(d->z, 0, 20, 0, 0.2);
  d->yspeed += grav * GetFrameTime() * 60;
  if (d->y > GetScreenHeight()) {
    d->y = RandomFloatBetween(-200, -100);
    d->yspeed = Map(d->z, 0, 20, 4, 10);
  }
}

void Drop_show(Drop* d) {
  float thick = Map(d->z, 0, 20, 1, 3);
  DrawLineEx((Vector2){d->x, d->y}, (Vector2){d->x, d->y + d->len}, thick,
             CLITERAL(Color){138, 43, 226, 255});
}
