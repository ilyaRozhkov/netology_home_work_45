#pragma once
#include "LogCommand.h"
#include <iostream>

class ConsoleLogCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};
