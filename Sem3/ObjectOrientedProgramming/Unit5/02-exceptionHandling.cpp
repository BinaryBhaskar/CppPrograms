#include <iostream>
#include <string>

// Custom Exception placeholder tracking validation failures
class NetworkDisconnectException {
public:
    std::string getErrorMessage() const { return "Network link dropped unexpectedly during transmission."; }
};

void executeTransaction(int processingCode) {
    if (processingCode == -1) {
        // 1. The throw Expression
        // Interrupts normal execution flow and sends an error object up the call stack.
        throw 404; 
    } 
    else if (processingCode == -2) {
        throw std::string("Database authentication signature mismatch.");
    } 
    else if (processingCode == -3) {
        throw NetworkDisconnectException(); // Throwing a custom user-defined object type
    }
    std::cout << "Transaction code " << processingCode << " processed normally." << std::endl;
}

int main() {
    std::cout << "=== TOPIC: EXCEPTION HANDLING MECHANICS ===" << std::endl;

    int testInputs[4] = {200, -1, -2, -3};

    for (int i = 0; i < 4; i++) {
        std::cout << "\nProcessing index item: " << i << std::endl;

        // 2. The try Block
        // Wraps code segment sections that might potentially encounter structural execution faults.
        try {
            executeTransaction(testInputs[i]);
        }
        // 3. Multiple Catch Blocks
        // Checked top-down by the compiler matching exact data signatures.
        catch (int errorCode) {
            std::cout << "[Caught Integer Fault]: Error Code Code " << errorCode << std::endl;
        }
        catch (const std::string& errorString) {
            std::cout << "[Caught String Fault]: Detail Log Message: " << errorString << std::endl;
        }
        catch (const NetworkDisconnectException& customException) {
            std::cout << "[Caught Object Fault]: Exception Notice: " << customException.getErrorMessage() << std::endl;
        }
        // 4. Catch-All Exception Handler (...)
        // MUST ALWAYS BE PLACED LAST. Intercepts any unspecified data signature variations.
        catch (...) {
            std::cout << "[Catch-All Triggered]: Mitigated an unmapped structural thread failure!" << std::endl;
        }
    }

    /* 5. UNCAUGHT EXCEPTIONS EXAM NOTE
        If a function throws an exception, and the runtime stack looks down through all available
        catch blocks and fails to locate an exact data-type match (and no catch-all block exists), 
        the application immediately terminates with an uncaught exception failure. 
        
        The runtime environment executes the standard system function `std::terminate()`, which calls 
        `abort()` to kill the application instance directly to prevent memory corruption.
    */

    return 0;
}