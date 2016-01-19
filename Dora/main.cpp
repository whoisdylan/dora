//#include <Windows.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "MainComponent.h"

int main(int argc, char **argv) {
  //OutputDebugString("this is how you print to the console in windows\n");

  MainComponent game;

  game.start();

  return 0;
}