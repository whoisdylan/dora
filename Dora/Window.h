#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Window {
public:
  Window(int, int, std::string, bool = false);

  void getSize(int *, int *);
  bool windowShouldClose();
  void render();

  GLFWwindow *window;
private:
};