#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening input.txt" << endl;
        return 1;
    }

    string content((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    if (content.empty()) {
        cerr << "File is empty." << endl;
        return 1;
    }

    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Error opening output.txt" << endl;
        return 1;
    }

    outputFile << content;
    outputFile.close();

    cout << "File copied successfully!" << endl;
    return 0;
}
