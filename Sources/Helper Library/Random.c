#include "Helper/Random.h"

#include <sodium/randombytes.h>

float RandomFloat() { return (float)randombytes_random() / (float)UINT32_MAX; }
float RandomFloatBetween(float min, float max) {
  return RandomFloat() * (max - min) + min;
}
