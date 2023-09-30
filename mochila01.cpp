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
vector<vector<int>> memo;

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
    if (index == problemData.size()) return 0;
    if (problemData[index][0] > bpSize) return backpack(index + 1, bpSize);
    if (memo[index][bpSize] != -1) return memo[index][bpSize];
    int r1 = backpack(index + 1, bpSize);
    int r2 = backpack(index + 1, bpSize - problemData[index][0]) + problemData[index][1];
    return memo[index][bpSize] = max(r1, r2);
}

double timeExec(chrono::high_resolution_clock::time_point *start){
   ios_base::sync_with_stdio(false);
   auto end = chrono::high_resolution_clock::now();
   return chrono::duration_cast<chrono::nanoseconds>(end - *start).count() * 1e-6;
}

int main() {

    int instance = 1;
    cin >> instance;
    auto mainStart = chrono::high_resolution_clock::now();
    
    auto start = chrono::high_resolution_clock::now();
    vector<int> fileData = input("input/instancia"+ to_string(instance) + ".txt");
    cout << "time to read file: " << timeExec(&start) << " ms"<< endl;

    start = chrono::high_resolution_clock::now();
    int backpackSize = fileData[1];
    //problemData = weight, value
    for (int i = 2; i < fileData.size(); ++i) {
        i++;
        problemData.push_back({fileData[i], fileData[i+1]});
        i++;
    }
    cout << "time to process data: " << timeExec(&start) << " ms"<< endl;

    //start memo with -1
    for (int i = 0; i < problemData.size(); ++i) {
        vector<int> row;
        for (int j = 0; j < backpackSize +1; ++j) {
            row.push_back(-1);
        }
        memo.push_back(row);
    }

    start = chrono::high_resolution_clock::now();
    int result =  backpack(0, backpackSize);
    cout << "time to execute: " << timeExec(&start) << " ms"<< endl;
    cout << "time to execute all: " << timeExec(&mainStart) << " ms"<< endl;
    cout << "result: " << result << endl;
    cout << "times in function:" << count << endl; 
    return 0;
}
