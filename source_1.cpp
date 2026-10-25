#include <iostream>
#include <fstream>
#include <string>
#include <memory>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class FileLogCommand : public LogCommand {
public:
    explicit FileLogCommand(std::string path) : path_(std::move(path)) {}

    void print(const std::string& message) override {
        std::ofstream out(path_, std::ios::app);
        if (!out.is_open()) {
            std::cerr << "Не удалось открыть файл: " << path_ << std::endl;
            return;
        }
        out << message << std::endl;
    }

private:
    std::string path_;
};

void print(LogCommand& command, const std::string& message) {
    command.print(message);
}

int main() {
    ConsoleLogCommand console;
    FileLogCommand    file("/tmp/log.txt");

    print(console, "Сообщение в консоль");
    print(file,    "Сообщение в файл");

    return 0;
}
