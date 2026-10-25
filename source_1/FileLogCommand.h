#pragma once
#include "LogCommand.h"
#include <fstream>
#include <stdexcept>
#include <utility>

class FileLogCommand : public LogCommand {
    std::string path_;
public:
    explicit FileLogCommand(std::string path) : path_(std::move(path)) {}

    void print(const std::string& message) override {
        std::ofstream out(path_, std::ios::app);
        if (!out) {
            throw std::runtime_error("Cannot open log file: " + path_);
        }
        out << message << std::endl;
    }
};
