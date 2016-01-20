#pragma once

#include "Window.h"

class MainComponent {
public:
  MainComponent();
  void start();
  void stop();

private:
  void run();
  void render();
  void cleanUp();

  Window doraWindow;
  bool isRunning;
  GLuint _vao;
  GLuint _vertex_shader;
  GLuint _fragment_shader;
};