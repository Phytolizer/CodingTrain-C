#pragma once

#include <raylib.h>
#include <stdbool.h>
#include <vec.h>

#define SCL 20

/// A collection of points in 3D space.
typedef vec_t(Vector3) vec_vector3_t;

/// The player controls the snake.
typedef struct Snake {
  /// The snake's horizontal position on the board.
  float x;
  /// The snake's vertical position on the board,
  /// relative to its top left corner.
  float y;
  /// The distance the snake will move horizontally per tick.
  float xspeed;
  /// The distance the snake will move vertically per tick.
  float yspeed;
  /// The length of the snake's tail.
  int total;
  /// The snake's tail. If it collides with any position in
  /// this list, the game ends.
  vec_vector3_t tail;
} Snake;

/// Initialize the snake. It will be in the top left corner, moving
/// to the right.
void Snake_init(Snake* s);
/// Clean up memory allocated by the snake's tail.
void Snake_deinit(Snake* s);

/// Check for and consume food at `pos`.
bool Snake_eat(Snake* s, Vector2 pos);
/// Change the snake's heading to `dir`.
void Snake_dir(Snake* s, Vector2 dir);
/// Check for death conditions (hitting wall,
/// running into self).
void Snake_death(Snake* s);
/// Move the snake by one tick forward.
void Snake_update(Snake* s);
/// Display the snake and its tail on screen.
void Snake_show(Snake* s);
