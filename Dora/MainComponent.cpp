#include "MainComponent.h"
#include <iostream>
#include <fstream>

MainComponent::MainComponent() :
  doraWindow(800, 600, "Dora", false),
  isRunning(false) {
  start();
}

void MainComponent::start() {
  if (isRunning) {
    return;
  }

  run();
}

void MainComponent::stop() {
  if (!isRunning) {
    return;
  }

  isRunning = false;
}

void MainComponent::run() {
  isRunning = true;
  while (isRunning) {
    if (doraWindow.windowShouldClose()) {
      stop();
    }
    glfwPollEvents();
    render();
    if (glfwGetKey(doraWindow.window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      glfwSetWindowShouldClose(doraWindow.window, GL_TRUE);
      return;
    }
  }
  cleanUp();
}

void MainComponent::render() {
  doraWindow.render();
}

void MainComponent::cleanUp() {
  glfwTerminate();
}