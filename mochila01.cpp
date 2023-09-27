//max value in the bag

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<vector<int>> input(){
    ifstream inputFile("input/instancia1.txt");

    if (!inputFile.is_open()) {
        cout << "Error!" << endl;
        exit(1);
        return {};
    }

    string line;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    inputFile.close();
    return {};
}

int main() {
    input();
    return 0;
}


