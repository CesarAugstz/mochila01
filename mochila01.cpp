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

    std::vector<int> numbers;
    // Read numbers from the file
    int number;
    while (inputFile >> number) {
        numbers.push_back(number);
    }

    // Close the file
    inputFile.close();

    // Now you have the numbers stored in the 'numbers' vector
    // You can perform operations on the data as needed

    // Print the numbers as an example
    vector<vector<int>> data;
    int backpackSize = numbers[1];
    for (int i = 2; i < numbers.size(); ++i) {
        i++;
        data.push_back({numbers[i], numbers[i+1]});
        i++;
    }
    // print formatted data
    for (int i = 0; i < data.size(); ++i) {
        cout << data[i][0] << "weight" << data[i][1] << "value" << endl;
    }
    return {};
}

int main() {
    input();
    return 0;
}


