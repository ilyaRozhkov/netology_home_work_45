#pragma once
#include <iostream>
#include "LogHandler.h"

class WarningHandler : public LogHandler {
protected:
    bool canHandle(const LogMessage& msg) const override {
        return msg.type() == Type::Warning;
    }

    void process(const LogMessage& msg) override {
        std::cout << "WARNING: " << msg.message() << std::endl;
    }
};
