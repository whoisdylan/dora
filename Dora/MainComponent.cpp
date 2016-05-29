#include "MainComponent.h"
#include <iostream>
#include <fstream>
#include <thread>
#include "RenderUtil.h"
#include "Shader.h"

MainComponent::MainComponent() :
  doraWindow(800, 600, "Dora", false),
  isRunning(false) {
  RenderUtil::initGraphics();
  start();
}

void MainComponent::start() {
  if (isRunning) {
    return;
  }

  static const float vertices[] =
  {
       0.25, -0.25, 0.5, 1.0,
      -0.25, -0.25, 0.5, 1.0,
       0.25,  0.25, 0.5, 1.0
  };

  Shader shader = Shader();
  glUseProgram(shader._program);

  GLuint vbo;

  glCreateBuffers(1, &vbo);
  glCreateVertexArrays(1, &_vao);

  glBindVertexArray(_vao);

  glNamedBufferStorage(vbo, sizeof(vertices), vertices, 0);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);

  glVertexArrayVertexBuffer(_vao, 0, vbo, 0, 16);
  glVertexArrayAttribFormat(_vao, 0, 4, GL_FLOAT, GL_FALSE, 0);
  glVertexArrayAttribBinding(_vao, 0, 0);
  glEnableVertexArrayAttrib(_vao, 0);
  glEnableVertexAttribArray(0);

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

  uint32_t fps = 0;
  double frameTimeSum = 0;
  double lastTime = glfwGetTime();
  double unprocessedTime = 0;

  while (isRunning) {
    bool shouldRender = false;
    double startTime = glfwGetTime();
    double passedTime = startTime - lastTime;
    lastTime = startTime;

    unprocessedTime += passedTime;
    frameTimeSum += passedTime;

    while (unprocessedTime > FRAME_TIME) {
      shouldRender = true;
      unprocessedTime -= FRAME_TIME;
      // update game

    }

    if (frameTimeSum >= 1.0) {
      std::cout << fps << std::endl;
      fps = 0;
      frameTimeSum = 0;
    }

    if (doraWindow.windowShouldClose()) {
      stop();
    }
    glfwPollEvents();
    if (shouldRender) {
      render();
      fps++;
    } else {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    if (glfwGetKey(doraWindow.window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      glfwSetWindowShouldClose(doraWindow.window, GL_TRUE);
      return;
    }
  }
  cleanUp();
}

void MainComponent::render() {
  RenderUtil::clearScreen();
  glDrawArrays(GL_TRIANGLES, 0, 3);
  doraWindow.render();
}

void MainComponent::cleanUp() {
  glfwTerminate();
}