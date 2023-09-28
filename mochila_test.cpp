
//max value in the bag

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int problemData[20][2];

int backpack(int index, int bpSize) { 
//    cout << "index: " << index << " bpSize: " << bpSize << endl;
    if (bpSize == 0) return 0;
    if (index == (sizeof problemData / sizeof problemData[0] )) return 0;
    if (problemData[index][0] > bpSize) return backpack(index + 1, bpSize);
    int r1 = backpack(index + 1, bpSize);
    int r2 = backpack(index + 1, bpSize - problemData[index][0]) + problemData[index][1];
    //return max(r1, r2);
    return max(r2, r1);
}


int main() {
    
    int backpackSize = 100;
	int profit[] = { 60, 100, 120, 10, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 10, 30, 40, 50, 60, 70, 80};
	int weight[] = { 10, 20, 30 , 40, 50, 60, 70, 80, 90, 100, 110, 120, 10, 30, 40, 50, 60, 70, 80, 90, 100};
    for (int i = 0; i < 20; ++i) {
        problemData[i][0] = weight[i];
        problemData[i][1] = profit[i];
    }

    int result =  backpack(0, backpackSize);
    cout << result << endl;
    return 0;
}


