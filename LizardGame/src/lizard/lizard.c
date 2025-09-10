#include "lizard.h"

Lizard createLizard(TextureManager *textureManager){
  Lizard liz;
  liz.pos = (Vector2){ SCREENWIDTH / 2, SCREENHEIGHT / 2 };
  liz.velocity = (Vector2){ 0.0f, 0.0f };
  liz.width = 64.0f;
  liz.height = 64.0f;
  liz.scale = 2.0f;
  liz.speed = 200.0f;
  liz.running = false;
  liz.amountOfFrames = 2;
  liz.currentFrame = 0;
  liz.frameTime = 0.0f;
  liz.frameSpeed = 0.3f;
  liz.frameRec = (Rectangle){ 0.0f, 0.0f, 32.0f, 32.0f };
  liz.texture = &textureManager->lizard;
  return liz;
}

void moveLizard(Lizard *lizard){
  float deltaTime = GetFrameTime();
  if (IsKeyDown(KEY_A)){
    lizard->pos.x -= lizard->speed * deltaTime;
    lizard->running = true;
  }
  else if (IsKeyDown(KEY_D)){ 
    lizard->pos.x += lizard->speed * deltaTime;
    lizard->running = true;
  }
  else{
    lizard->running = false;
  }
}

void drawLizard(Lizard *lizard){
  Rectangle source = lizard->frameRec;
  Rectangle destRec = { lizard->pos.x, lizard->pos.y, lizard->width * lizard->scale, lizard->height * lizard->scale };
  Vector2 origin = { 0, 0 };
  float rotation = 0.0f;
  DrawTexturePro(*lizard->texture, source, destRec, origin, rotation, WHITE);
}

void updateAnimationLizard(Lizard *lizard){
  if(!lizard->running){
    lizard->amountOfFrames = 1;
    lizard->frameSpeed = 0.2f;
    lizard->frameTime += GetFrameTime();
    if (lizard->frameTime >= lizard->frameSpeed) {
      lizard->frameTime = 0.0f;
      lizard->currentFrame++;
      if (lizard->currentFrame > lizard->amountOfFrames) lizard->currentFrame = 0;
      lizard->frameRec.y = (float)lizard->currentFrame * lizard->frameRec.height;
    }
  }
  else if(lizard->running){
    lizard->amountOfFrames = 4;
    lizard->frameSpeed = 0.1f;
    lizard->frameTime += GetFrameTime();
    if (lizard->frameTime >= lizard->frameSpeed) {
      lizard->frameTime = 0.0f;
      lizard->currentFrame++;
      if (lizard->currentFrame > lizard->amountOfFrames) lizard->currentFrame = 2;
      lizard->frameRec.y = (float)lizard->currentFrame * lizard->frameRec.height;
    }
  }
}

void updateLizard(Lizard *lizard){
  drawLizard(lizard);
  updateAnimationLizard(lizard);
  moveLizard(lizard);
}
