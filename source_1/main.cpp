#include "LogCommand.h"
#include "ConsoleLogCommand.h"
#include "FileLogCommand.h"
#include <iostream>

void print(LogCommand& cmd, const std::string& message) {
    cmd.print(message);
}

int main() {
    ConsoleLogCommand console;
    FileLogCommand    file("app.log");

    print(console, "Hello, console!");
    print(file,    "Hello, file!");
    print(console, "Second message to console.");

    return 0;
}
