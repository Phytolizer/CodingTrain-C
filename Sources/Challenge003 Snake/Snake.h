#pragma once

#include <raylib.h>
#include <stdbool.h>
#include <vec.h>

#define SCL 20

typedef vec_t(Vector3) vec_vector3_t;

typedef struct Snake_s {
  float x;
  float y;
  float xspeed;
  float yspeed;
  int total;
  vec_vector3_t tail;
} Snake;

void Snake_init(Snake* s);
void Snake_deinit(Snake* s);

bool Snake_eat(Snake* s, Vector2 pos);
void Snake_dir(Snake* s, Vector2 dir);
void Snake_death(Snake* s);
void Snake_update(Snake* s);
void Snake_show(Snake* s);
