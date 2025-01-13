#pragma once
#include <string>
#include <exception>

class Exception : public std::exception {
protected:
  std::string errorMessage;

public:
  explicit Exception(const std::string &msg) : errorMessage(msg) {
  }

  ~Exception() noexcept override {
  }

  [[nodiscard]] const char *what() const noexcept override {
    return errorMessage.c_str();
  }
};

class FilePathError : public Exception {
  std::string filePath;

public:
  explicit FilePathError(const std::string &fp) : Exception("Error opening file: "), filePath(fp) {
    errorMessage += filePath + "!";
  }
};

class ContentObjectError : public Exception {
public:
  explicit ContentObjectError(const std::string &msg) : Exception("Content Object Error: " + msg) {
  }
};

class UpcastError : public Exception {
public:
  explicit UpcastError(const std::string &msg) : Exception("Upcast Error: " + msg) {
  }
};

