#include <cstdlib>
#include <iostream>
#include <cstdio>

int main() {
    // Execute the Python script and capture the output
    FILE *output = popen("cd lib/python & python try.py", "r");

    // Read the output and convert it to an integer
    char buffer[128];
    if (output && fgets(buffer, sizeof(buffer), output) != nullptr) {
        int result = std::atoi(buffer);
        std::cout << "Result from Python script: " << result << std::endl;
    } else {
        if (output) {
            std::cerr << "Error reading output from Python script." << std::endl;
        } else {
            std::cerr << "Error executing Python script or no output received." << std::endl;
        }

        // Print additional information about the error
        perror("popen");

        return 1;
    }

    // Close the file stream
    pclose(output);

    return 0;
}
