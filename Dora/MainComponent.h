#pragma once

#include "Window.h"

class MainComponent {
public:
  MainComponent();
  void start();

private:
  void stop();
  void run();
  void render();
  void cleanUp();

  Window doraWindow;
};