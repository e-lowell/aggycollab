#define fps 60
#include <cstdio>
#include <string>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "globalvars.h"
#include "tile.h"
#include "physics.h"
#include "renderer.h"
#include "player.h"
#include "physics.cpp"
#include "renderer.cpp"
#include "tile.cpp"
#include "player.cpp"

int main(int argc, char* args[]) {
  init();
  gTileTexture.loadFromFile("resources/tiles/tiles1.png");
  setTiles(tileSet);
  gPlayerTexture.loadFromFile("resources/player/player.png");
  bool quit = false;
  SDL_Event e;
  while(!quit) {
    Uint32 starting_tick = SDL_GetTicks();
    player.setCamera(camera);
    for(int i = 0; i < TOTAL_TILES; i++) {
	tileSet[i]->render(camera, true);
    }
    player.move(tileSet);
    player.render(camera);
    for(int i = 0; i < TOTAL_TILES; i++) {
      if(tileSet[i]->renderOver)
	tileSet[i]->render(camera, false);
    }
    while(SDL_PollEvent(&e) != 0){
      //User requests quit
      if(e.type == SDL_QUIT)
	quit = true;
      player.handleEvent(e);
    }
    SDL_RenderPresent(gRenderer);
    SDL_RenderClear(gRenderer);
    if( (1000/fps) > SDL_GetTicks() - starting_tick ) {
      SDL_Delay(1000/fps - (SDL_GetTicks() - starting_tick));
    }
  }
  close();
}
