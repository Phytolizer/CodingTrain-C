#pragma once

typedef struct Star {
  float x;
  float y;
  float z;
} Star;

void Star_init(Star* star);
void Star_update(Star* star);
void Star_show(Star* star);
