#pragma once
#include <fstream>
#include <stdexcept>
#include <utility>
#include "LogHandler.h"

class ErrorHandler : public LogHandler {
public:
    explicit ErrorHandler(std::string path) : path_(std::move(path)) {}

protected:
    bool canHandle(const LogMessage& msg) const override {
        return msg.type() == Type::Error;
    }

    void process(const LogMessage& msg) override {
        std::ofstream out(path_, std::ios::app);
        if (!out) {
            throw std::runtime_error("Cannot open log file: " + path_);
        }
        out << msg.message() << '\n';
    }

private:
    std::string path_;
};
