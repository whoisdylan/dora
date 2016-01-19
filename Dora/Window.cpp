#include "Window.h"

Window::Window(int width, int height, std::string title, bool fullscreen = false) {
  glfwInit();

  //request a core opengl context
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  if (fullscreen) {
    // fullscreen
    window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), nullptr);
  } else {
    // windowed
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
  }
  glfwMakeContextCurrent(window);

  //init glew with modern opengl
  glewExperimental = GL_TRUE;
  glewInit();

  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
}