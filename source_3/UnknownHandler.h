#pragma once
#include <stdexcept>
#include "LogHandler.h"

class UnknownHandler : public LogHandler {
protected:
    bool canHandle(const LogMessage& msg) const override {
        return msg.type() == Type::Unknown;
    }

    void process(const LogMessage& msg) override {
        throw std::runtime_error("Unhandled message: " + msg.message());
    }
};
