#include "logger.hpp"

Logger& LOG() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}