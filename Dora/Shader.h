#pragma once

#include <GL/glew.h>
#include <string>
#include <iostream>
#include <fstream>

class Shader {
public:
  Shader();

  void readShaderFile(const std::string &, std::string &);
  GLuint addShaderToProgram(const std::string &, GLenum);

  GLuint _program;

private:
};
