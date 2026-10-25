#pragma once
#include <stdexcept>
#include "LogHandler.h"

class FatalErrorHandler : public LogHandler {
protected:
    bool canHandle(const LogMessage& msg) const override {
        return msg.type() == Type::FatalError;
    }

    void process(const LogMessage& msg) override {
        throw std::runtime_error(msg.message());
    }
};
