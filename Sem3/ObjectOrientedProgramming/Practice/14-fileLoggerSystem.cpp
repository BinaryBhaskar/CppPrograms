// Practice Problem 14: File Logger System (Text File I/O)
// Concepts Tested: File Output Stream (std::ofstream), File Input Stream (std::ifstream), File Modes (std::ios::app), Error Checking.
//
// Description:
// Implement a Logger class that writes formatted log entries (INFO, WARNING, ERROR) to a file named `app.log`
// and allows reading back the log history.
//
// Requirements:
// 1. Create a class named 'Logger':
//    - Private Member: std::string logFileName
// 2. Public Functions:
//    - Logger(std::string fileName = "app.log"): Initializes log file name.
//    - void log(std::string level, std::string message):
//      Opens file in append mode (`std::ios::app`).
//      Writes line in format: `[LEVEL] Message`.
//      Validates file opening; prints error message if file fails to open.
//    - void readLogs() const:
//      Opens file in input mode (`std::ifstream`).
//      Reads file line by line using `std::getline` and outputs all lines to console.
//      Closes file properly.
//    - void clearLogs():
//      Opens file in `std::ios::trunc` mode to clear existing log contents.
// 3. In main():
//    - Instantiate Logger object.
//    - Log an INFO message, a WARNING message, and an ERROR message.
//    - Call `readLogs()` to read back and display the log contents from `app.log`.

#include <iostream>
#include <fstream>
#include <string>

// TODO: Define your Logger class here

int main() {
    // TODO: Test writing and reading text files using Logger class

    return 0;
}
