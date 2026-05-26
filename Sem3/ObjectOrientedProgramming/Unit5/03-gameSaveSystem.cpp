// Concepts: Binary File Streams (ofstream/ifstream), Binary block write/read parsing, Stream state loop EOF tracking.
// Task: Build a lightweight game checkpoint save system that writes a structure block directly to a binary file and reads it back safely.
// Requirements:
// Create a struct named GameState with an integer level and a character array playerName[16].
// In main(), instantiate an array of two profiles: {"PlayerOne", 5} and {"PlayerTwo", 12}.
// Open a file named savestate.dat in binary write mode. Use the raw byte writer method (.write()) paired with a reinterpret_cast conversion to write both elements to disk in succession. Close the stream.
// Re-open the same file in binary read mode.
// Establish a while(true) reading sequence loop. Pull the structure chunks back one block at a time using .read().
// Crucial Step: Write an immediate validation condition checking for .eof(). Ensure your program terminates the reading loop cleanly without printing duplicate values or garbage blocks at the end of the data file. Close the stream.

#include <iostream>
#include <fstream>

struct GameState {
    int level;
    char playerName[16];
};

int main() {
    std::string filename = "savestate.dat";

    std::ofstream outfile(filename, std::ios::out | std::ios::binary);

    GameState profiles[2] = {
        {5, "PlayerOne"},
        {12, "PlayerTwo"}
    };

    for (const GameState& profile : profiles) {
        outfile.write(reinterpret_cast<const char*>(&profile), sizeof(GameState));
    }

    outfile.close();

    std::ifstream infile(filename, std::ios::in | std::ios::binary);

    GameState loadedProfile;
    while (infile.read(reinterpret_cast<char*>(&loadedProfile), sizeof(GameState))) {
        std::cout << "Level: " << loadedProfile.level << ", Name: " << loadedProfile.playerName << std::endl;
    }

    infile.close();
    return 0;
}