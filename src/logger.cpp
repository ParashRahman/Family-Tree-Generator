#include <iostream>
#include <string>

#include "logger.h"

const bool Logger::on = true;

void Logger::log(std::string str) {
  if (Logger::on) {
    std::cout << str << std::endl;
  }
}
