#include "Shader.h"

Shader::Shader() {
  _program = glCreateProgram();

  std::string vertexShaderCode, fragmentShaderCode;
  readShaderFile("VertexShader.glsl", vertexShaderCode);
  readShaderFile("FragmentShader.glsl", fragmentShaderCode);

  GLuint vertexShader = addShaderToProgram(vertexShaderCode, GL_VERTEX_SHADER);
  GLuint fragmentShader = addShaderToProgram(fragmentShaderCode, GL_FRAGMENT_SHADER);

  glLinkProgram(_program);
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

GLuint Shader::addShaderToProgram(const std::string &shaderCode, GLenum shaderType) {
  GLuint shader = glCreateShader(shaderType);
  const GLchar *p[1] { shaderCode.c_str() };
  const GLint lengths[1] { (GLint) shaderCode.length() };
  glShaderSource(shader, 1, p, lengths);

  glCompileShader(shader);
  GLint success;
  GLchar infoLog[512];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, 512, NULL, infoLog);
    std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  }

  glAttachShader(_program, shader);
  return shader;
}

void Shader::readShaderFile(const std::string &filename, std::string &shaderCode) {
  std::ifstream shaderFile(filename);

  if (shaderFile.is_open()) {
    while (shaderFile.good()) {
      std::string line;
      getline(shaderFile, line);
      if (line.find("#include") == std::string::npos) {
        shaderCode.append(line + "\n");
      } else {
        int breakPoint = (int) line.find(" ");
        std::string includeFileName = line.substr(breakPoint, line.length() - breakPoint);
        includeFileName = includeFileName.substr(1, includeFileName.length() - 2);
        std::string includeFileCode;
        readShaderFile(includeFileName, includeFileCode);
        shaderCode.append(includeFileCode + "\n");
      }
    }
    shaderFile.close();
  } else {
    std::cerr << "Unable to read shader file \"" << filename << "\"" << std::endl;
  }
}