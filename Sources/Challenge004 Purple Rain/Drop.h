#pragma once

typedef struct Drop_s {
  float x;
  float y;
  float z;
  float len;
  float yspeed;
} Drop;

void Drop_init(Drop* d);
void Drop_fall(Drop* d);
void Drop_show(Drop* d);
