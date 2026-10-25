#include "WarningObserver.h"
#include <iostream>

void WarningObserver::onWarning(const std::string& message) {
    std::cout << "[WARNING] " << message << std::endl;
}
