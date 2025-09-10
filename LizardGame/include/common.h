#ifndef COMMON_H
#define COMMON_H

#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

//GLOBAL CONSTANTS 

#define SCREENWIDTH 1400
#define SCREENHEIGHT 1000
#define TARGETFPS 0

typedef struct{
  Texture2D lizard;
}TextureManager;

typedef struct{
  Vector2 pos;
  Vector2 velocity;
  float width;
  float height;
  float scale;
  float speed;
  bool running;
  int amountOfFrames;
  int currentFrame;
  float frameTime;
  float frameSpeed;
  Rectangle frameRec;
  Texture2D *texture;
}Lizard;

#endif
