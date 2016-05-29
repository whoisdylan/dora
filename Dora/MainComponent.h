#pragma once

#include <GL/glew.h>
#include "Window.h"

class MainComponent {
public:
  MainComponent();
  void start();
  void stop();

  GLuint _vao;

private:
  void run();
  void render();
  void cleanUp();

  Window doraWindow;
  bool isRunning;
  const double FRAME_TIME = 1.0/5000.0;
};