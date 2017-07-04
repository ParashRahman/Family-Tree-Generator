#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>

class Logger {
 public:
  static const bool on;
  static void log(std::string str);
};

#endif
