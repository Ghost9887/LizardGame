#include "common.h"


int main(){
  
  InitWindow(SCREENWIDTH, SCREENHEIGHT, "Lizard Game");
  SetTargetFPS(TARGETFPS);

  while(!WindowShouldClose()){
    
    BeginDrawing();
      
      ClearBackground(WHITE);

      DrawText("Lizard Game", SCREENWIDTH / 2, SCREENHEIGHT / 2, 40, BLACK);

    EndDrawing();

  }

  CloseWindow();

  return 0;
}
