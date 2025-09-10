#include "common.h"
#include "textureManager.h"
#include "lizard.h"

void updateGameState(Lizard *lizard);

int main(){
  
  InitWindow(SCREENWIDTH, SCREENHEIGHT, "Lizard Game");
  SetTargetFPS(TARGETFPS);

  //Game Objects
  TextureManager tm = createTextureManager();
  Lizard lizard = createLizard(&tm);

  while(!WindowShouldClose()){
    
    BeginDrawing();
      
      ClearBackground(WHITE);
      
      updateGameState(&lizard);

    EndDrawing();

  }

  CloseWindow();

  return 0;
}

void updateGameState(Lizard *lizard){

  updateLizard(lizard);

}
