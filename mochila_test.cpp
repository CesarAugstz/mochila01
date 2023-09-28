
//max value in the bag

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<int> profit;
int memo[100][100];

int backpack(int index, int bpSize) { 
    if (bpSize == 0) return 0;
    if (memo[index][bpSize] != -1) return memo[index][bpSize];
    int r1 = backpack(index + 1, bpSize);
    int r2 = profit[index] + backpack(index + 1, bpSize - 1);  
    return memo[index][bpSize] = max(r1, r2);
}


int main() {

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            memo[i][j] = -1;
        }
    }

    vector<vector<int>> data;
    int backpackSize = 100;
    //format data filedData[1] = height, fileData[2] = value
    data = {{1, 1}, {2, 6}, {5, 18}, {6, 22}, {7, 28}};

    int result =  backpack(0, backpackSize);
    cout << result << endl;
    return 0;
}


