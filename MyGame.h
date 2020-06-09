#pragma once
#include "Game.h"
#include<iostream>

using std::cout;
using std::endl;

const double MS_UPDATE_TIME = 16;
const int SCRN_WIDTH = 320;
const int SCRN_HEIGHT = 240;

class MyGame : public Game{

  public:
    MyGame(): Game( SCRN_WIDTH, SCRN_HEIGHT ){}
    MyGame( int w, int h ) : Game(w, h) {}
    void start() override;

  private:
    Uint64 currentTime;
    Uint64 prevTime;
    double dt;
    SDL_Rect rect;
    bool isPlaying;

    void update( double& dt  ) override;
    void render() override;
    void processInput();
    void processWindowInput();


    void gameInit();
    void renderGrid();
    void updateGrid( double dt );
    void diffuse( double dt );

};
