#include <iostream>
#include <fstream> // MANDATORY FOR FILE I/O OPERATIONS

struct UserRecord {
    int id;
    char username[20];
};

int main() {
    std::cout << "=== TOPIC: WORKING WITH FILES (STREAM I/O) ===" << std::endl;

    std::string filename = "userData.bin";

    // 1. Opening a File for Output (Writing Binary Data)
    // std::ofstream is the output stream class. 
    // ios::binary format forces raw data transfer instead of plain text conversions.
    std::ofstream outFile(filename, std::ios::out | std::ios::binary);

    if (!outFile) {
        std::cerr << "CRITICAL ERROR: Unable to instantiate file system buffer stream." << std::endl;
        return 1;
    }

    UserRecord writeBuffer1 = { 101, "Bhaskar" };
    UserRecord writeBuffer2 = { 102, "Gemini" };

    // 2. The write() Function
    // Expects a parameter signature matching (char*, size_in_bytes).
    // We use reinterpret_cast to force a raw pointer layout transformation.
    outFile.write(reinterpret_cast<char*>(&writeBuffer1), sizeof(UserRecord));
    outFile.write(reinterpret_cast<char*>(&writeBuffer2), sizeof(UserRecord));

    // 3. Closing a File
    // Explicitly flushes the stream buffer and unlocks the system file handle resource.
    outFile.close();
    std::cout << "Binary blocks securely dispatched to storage medium." << std::endl;


    std::cout << "\n--- Initiating File Readback Loop ---" << std::endl;
    
    // 4. Opening a File for Input (Reading Binary Data)
    // std::ifstream is the input stream class.
    std::ifstream inFile(filename, std::ios::in | std::ios::binary);

    if (!inFile) {
        std::cerr << "CRITICAL ERROR: Target data container not located on disk." << std::endl;
        return 1;
    }

    UserRecord readBuffer;

    // 5. Detecting End of File (.eof())
    // Loop continues reading data blocks until the input stream head hits the terminal file margin.
    while (true) {
        // The read() Function
        // Pulls a raw chunk of memory matching the size of our structure directly from disk.
        inFile.read(reinterpret_cast<char*>(&readBuffer), sizeof(UserRecord));

        // Always check for EOF immediately after an attempted read sequence
        if (inFile.eof()) {
            std::cout << "[EOF Detected] Terminal data block boundaries reached." << std::endl;
            break; 
        }

        std::cout << "Parsed Record -> ID: " << readBuffer.id << ", Username: " << readBuffer.username << std::endl;
    }

    inFile.close();
    return 0;
}