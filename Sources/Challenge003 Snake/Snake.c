#include "Snake.h"

#include <Helper/Math.h>
#include <stdio.h>

void Snake_init(Snake* s) {
  s->x = 0;
  s->y = 0;
  s->xspeed = 1;
  s->yspeed = 1;
  s->total = 0;
  vec_init(&s->tail);
}

void Snake_deinit(Snake* s) { vec_deinit(&s->tail); }

bool Snake_eat(Snake* s, Vector2 pos) {
  float d = Distance2D(pos, (Vector2){s->x, s->y});
  if (d < 1) {
    ++s->total;
    return true;
  }
  return false;
}

void Snake_dir(Snake* s, Vector2 dir) {
  s->xspeed = dir.x;
  s->yspeed = dir.y;
}

void Snake_death(Snake* s) {
  for (int i = 0; i < s->tail.length; ++i) {
    Vector3* pos = &s->tail.data[i];
    float d = Distance2D((Vector2){pos->x, pos->y}, (Vector2){s->x, s->y});
    if (d < 1) {
      printf("starting over\n");
      s->total = 0;
      s->tail.length = 0;
    }
  }
}

void Snake_update(Snake* s) {
  if (s->total > 0) {
    if (s->total == s->tail.length && s->tail.length > 0) {
      vec_splice(&s->tail, 0, 1);
    }
    vec_push(&s->tail, ((Vector3){s->x, s->y, 0}));
  }

  s->x += s->xspeed * SCL;
  s->y += s->yspeed * SCL;

  s->x = Constrain(s->x, 0, GetScreenWidth() - SCL);
  s->y = Constrain(s->y, 0, GetScreenHeight() - SCL);
}

void Snake_show(Snake* s) {
  for (int i = 0; i < s->tail.length; ++i) {
    DrawRectangle(s->tail.data[i].x, s->tail.data[i].y, SCL, SCL, WHITE);
  }
  DrawRectangle(s->x, s->y, SCL, SCL, WHITE);
}
