#include "Helper/Math.h"

#include <math.h>

float Map(float value, float start1, float stop1, float start2, float stop2) {
  return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
}

float Constrain(float value, float start, float stop) {
  return (value < start) ? start : (value > stop) ? stop : value;
}

float Distance2D(Vector2 v1, Vector2 v2) {
  float dx = v2.x - v1.x;
  float dy = v2.y - v1.y;
  return sqrtf(dx * dx + dy * dy);
}
