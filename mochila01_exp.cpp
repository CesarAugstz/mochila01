//max value in the bag

#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;
long long int count = 0;
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
    count ++;
    if (bpSize == 0) return 0;
    if (index == /*problemData.size()*/150) return 0;
    if (problemData[index][0] > bpSize) return backpack(index + 1, bpSize);
    int r1 = backpack(index + 1, bpSize);
    int r2 = backpack(index + 1, bpSize - problemData[index][0]) + problemData[index][1];
    //return max(r1, r2);
    return max(r2, r1);
}

double timeExec(chrono::high_resolution_clock::time_point *start){
   ios_base::sync_with_stdio(false);
   auto end = chrono::high_resolution_clock::now();
   return chrono::duration_cast<chrono::nanoseconds>(end - *start).count() * 1e-9;
}

int main() {

    auto mainStart = chrono::high_resolution_clock::now();
    
    auto start = chrono::high_resolution_clock::now();
    vector<int> fileData = input("input/instancia1.txt");
    cout << "time to read file: " << timeExec(&start) << " sec"<< endl;

    start = chrono::high_resolution_clock::now();
    int backpackSize = fileData[1];
    //problemData = weight, value
    for (int i = 2; i < fileData.size(); ++i) {
        i++;
        problemData.push_back({fileData[i], fileData[i+1]});
        i++;
    }
    cout << "time to process data: " << timeExec(&start) << " sec"<< endl;

    start = chrono::high_resolution_clock::now();
    int result =  backpack(0, backpackSize);
    cout << "time to execute: " << timeExec(&start) << " sec"<< endl;
    cout << "time to execute all: " << timeExec(&mainStart) << " sec"<< endl;
    cout << "result: " << result << " times in function:" << count << endl; 
    return 0;
}
