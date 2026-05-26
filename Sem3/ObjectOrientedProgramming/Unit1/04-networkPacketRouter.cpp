// Problem 2: The Network Packet Router
// Concepts Tested: Anonymous Unions, Enums, Tag Names, Structure vs. Class.
// Simulate a network router that processes different kinds of data packets using minimal memory.
// Requirements:
// Define an enum with the tag name PacketType containing values PING, TEXT, and MEDIA.
// Create a struct with the tag name Packet. Inside it, put a PacketType variable to hold the type.
// Inside the Packet struct, create an anonymous union to hold the payload data. It should contain an int pingID and a char message[4].
// In main(), create a Packet object. Set its type to TEXT. Assign the character array "SOS" to its message buffer.
// Print the values to show that accessing pingID now prints a weird integer value because they share the exact same memory space.

#include <iostream>
#include <cstring>

enum PacketType { PING, TEXT, MEDIA };

struct Packet {
    PacketType type;

    union {
        int pingID;
        char message[4];
    };
};

int main() {
    Packet p1;

    p1.type = TEXT;

    strcpy(p1.message, "SOS");

    std::cout << p1.pingID << std::endl;
}