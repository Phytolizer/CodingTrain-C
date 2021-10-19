#pragma once

/// A star in the starfield.
///
/// The z coordinate is used for a pseudo-3D effect.
typedef struct Star {
  /// The x coordinate of the star in world space.
  float x;
  /// The y coordinate of the star in world space.
  float y;
  /// The z coordinate of the star in world space.
  float z;
} Star;

/// Initialize a `Star`. It will be given a random
/// position.
void Star_init(Star* star);
/// Update the `Star`'s position. Its `z` value will
/// be reduced by a small amount on each call.
void Star_update(Star* star);
/// Display the `Star` on screen.
void Star_show(Star* star);
