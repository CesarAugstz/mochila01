//max value in the bag

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<int> input(string path){
    ifstream inputFile(path);

    if (!inputFile.is_open()) {
        cout << "Error!" << endl;
        exit(1);
    }

    vector<int> numbers;
    int number;
    while (inputFile >> number) {
        numbers.push_back(number);
    }

    inputFile.close();

    return numbers;
}

int main() {
    vector<int> fileData = input("input/instancia1.txt");
    
    vector<vector<int>> data;
    int backpackSize = fileData[1];
    //format data filedData[1] = height, fileData[2] = value
    for (int i = 2; i < fileData.size(); ++i) {
        i++;
        data.push_back({fileData[i], fileData[i+1]});
        i++;
    }

    return 0;
}


