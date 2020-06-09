#pragma once
#include<SDL2/SDL.h>
#include<iostream>

class Game{

  protected:
    const int DELAY = 16;
    int window_width;
    int window_height; 
    char* title; 
    int xMouse, yMouse;

    //SDL Components
    SDL_Window* window; 
    SDL_Renderer* renderer;

    virtual void update( double& dt ){};
    virtual void render(){};
    int initWindow(){
      window = SDL_CreateWindow( title,
                   SDL_WINDOWPOS_CENTERED,
                   SDL_WINDOWPOS_CENTERED,
                   window_width,
                   window_height,
                   0);

      if(!window)
      {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
      }
      return 0;  
    }

    int initRenderer(){

      renderer = SDL_CreateRenderer(
                              window,
                              -1,
                              SDL_RENDERER_ACCELERATED);
      if ( renderer == nullptr )
      {
        std::cout << "Failed to create renderer : " << SDL_GetError();
        return false;
      }

      return 0;
    };

    int initGame(){

      if(SDL_Init(SDL_INIT_VIDEO) < 0)
      {
        std::cout << "Failed to initialize the SDL2 library\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
      }

      initWindow(); 
      initRenderer();
      return 1;
    };

  public:
    Game(){
      initGame();
    };

    Game( int w=680, int h=480){

      title = (char *)"Game";
      window_width  = w; 
      window_height = h; 
      
      initGame();
    };

    Game( char* label=(char *)"Game", int w=680, int h=480 ){

      title = label;
      window_width  = w;
      window_height = h;

      initGame();
    };
    virtual void start(){};
};
