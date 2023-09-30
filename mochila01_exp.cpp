//max value in the bag

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
int count = 0;
vector<vector<int>> problemData;

int max(int a, int b) { return (a > b) ? a : b; }
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

int backpack(int index, int bpSize) { 
    cout << "index: " << index << " bpSize: " << bpSize << endl;
    count ++;
    if (bpSize == 0) return 0;
    if (index == (sizeof problemData / sizeof problemData[0] )) return 0;
    if (problemData[index][0] > bpSize) return backpack(index + 1, bpSize);
    int r1 = backpack(index + 1, bpSize);
    int r2 = backpack(index + 1, bpSize - problemData[index][0]) + problemData[index][1];
    //return max(r1, r2);
    return max(r2, r1);
}


int main() {
    
    vector<int> fileData = input("input/instancia1.txt");

    int backpackSize = fileData[1];
    //format data filedData[1] = height, fileData[2] = value
    for (int i = 2; i < fileData.size(); ++i) {
        i++;
        problemData.push_back({fileData[i], fileData[i+1]});
        //cout << "height: " << fileData[i] << " value: " << fileData[i+1] << endl;
        i++;
    }

    int result =  backpack(0, backpackSize);
    cout << "result: " << result << " times in function:" << count << endl; 
    return 0;
}
