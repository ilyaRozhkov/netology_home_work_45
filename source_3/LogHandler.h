#pragma once
#include <memory>
#include "LogMessage.h"

class LogHandler {
public:
    virtual ~LogHandler() = default;

    void setNext(std::shared_ptr<LogHandler> next) {
        next_ = std::move(next);
    }

    void handle(const LogMessage& msg) {
        if (canHandle(msg)) {
            process(msg);
        } else if (next_) {
            next_->handle(msg);
        }
    }

protected:
    virtual bool canHandle(const LogMessage& msg) const = 0;
    virtual void process(const LogMessage& msg) = 0;

    std::shared_ptr<LogHandler> next_;
};
