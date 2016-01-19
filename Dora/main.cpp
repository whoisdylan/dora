//#include <Windows.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char **argv) {
  //OutputDebugString("this is how you print to the console in windows\n");

  glfwInit();

  //request a core opengl context
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  // windowed
  GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr);
  // fullscreen
  //GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), nullptr);
  glfwMakeContextCurrent(window);

  //init glew with modern opengl
  glewExperimental = GL_TRUE;
  glewInit();

  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);

  std::cout << vertexBuffer << std::endl;

  while (!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      glfwSetWindowShouldClose(window, GL_TRUE);
    }
  }
  
  glfwTerminate();
  return 0;
}