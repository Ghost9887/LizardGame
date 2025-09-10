#include "textureManager.h"

TextureManager createTextureManager(){
  TextureManager tm;
  tm.lizard = LoadTexture("assets/lizard/lizard.png");
  return tm;
}
