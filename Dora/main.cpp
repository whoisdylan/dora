//#include <Windows.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"

int main(int argc, char **argv) {
  //OutputDebugString("this is how you print to the console in windows\n");

  Window doraWindow(800, 600, "Dora", false);

  while (!glfwWindowShouldClose(doraWindow.window)) {
    glfwSwapBuffers(doraWindow.window);
    glfwPollEvents();
    if (glfwGetKey(doraWindow.window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      glfwSetWindowShouldClose(doraWindow.window, GL_TRUE);
    }
  }
  
  glfwTerminate();
  return 0;
}