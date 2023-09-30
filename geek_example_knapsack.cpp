/* A Naive recursive implementation of
0-1 Knapsack problem */
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
int timess = 0;

vector<vector<int>> problemData;
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

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
    timess++;
    cout << "W: " << W << " n: " << n << " wt: " << wt[n-1] << " val: " << val[n-1] << endl;
	// Base Case
	if (n == 0 || W == 0)
		return 0;

	// If weight of the nth item is more
	// than Knapsack capacity W, then
	// this item cannot be included
	// in the optimal solution
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);

	// Return the maximum of two cases:
	// (1) nth item included
	// (2) not included
	else
		return max(
			val[n - 1]
				+ knapSack(W - wt[n - 1], wt, val, n - 1),
			knapSack(W, wt, val, n - 1));
}

// Driver code
int main()
{

    cout << "reading file" << endl;
    vector<int> fileData = input("input/instancia1.txt");

    int backpackSize = fileData[1];
    //format data filedData[1] = height, fileData[2] = value
    cout << "fileData size: " << fileData.size() << endl;
    for (int i = 2; i < fileData.size(); ++i) {
        i++;
        problemData.push_back({fileData[i], fileData[i+1]});
        //cout << "height: " << fileData[i] << " value: " << fileData[i+1] << endl;
        i++;
    }
    vector<int> profit;
	vector<int> weight;
    cout << "problemData size: " << problemData.size() << endl;
    for (int i = 0; i < problemData.size(); ++i) {
        weight.push_back(problemData[i][0]);
        profit.push_back(problemData[i][1]);
    }
	int W = backpackSize;
	int n = sizeof(profit) / sizeof(profit[0]);
	cout << knapSack(W, weight, profit, n) << endl;
    cout << "times timess: " << timess << endl;
	return 0;
}

// This code is contributed by rathbhupendra

