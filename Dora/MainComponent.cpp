#include "MainComponent.h"
#include <iostream>

MainComponent::MainComponent() :
  doraWindow(800, 600, "Dora", false) {
  start();
}

void MainComponent::start() {
  run();
}

void MainComponent::stop() {
  glfwSetWindowShouldClose(doraWindow.window, GL_TRUE);
}

void MainComponent::run() {
  while (!doraWindow.windowShouldClose()) {
    glfwPollEvents();
    render();
    if (glfwGetKey(doraWindow.window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      stop();
      return;
    }
  }
  glfwTerminate();
}

void MainComponent::render() {
  doraWindow.render();
}

void MainComponent::cleanUp() {

}