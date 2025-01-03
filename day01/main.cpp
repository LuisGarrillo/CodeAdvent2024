#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string input);

int main() {
    vector<int> leftList;
    vector<int> rightList;
    int totalDistance = 0;
    int similarityScore = 0;

    // Read input file and store the location id lists
    ifstream input("input.in");
    string line;
    
    while(getline(input, line)) {
        vector<string> splittedLine = split(line);
        leftList.push_back(stoi(splittedLine[0]));
        rightList.push_back(stoi(splittedLine[1]));
    }
    input.close();

    // Sort location ID lists

    int length = leftList.size();
    int aux = 0;
    for (int i = 0; i < length; i ++) {
        for (int j = i + 1; j < length; j ++) {
            if (leftList[i] > leftList[j]) {
                aux = leftList[i];
                leftList[i] = leftList[j];
                leftList[j] = aux;
            }
            if (rightList[i] > rightList[j]) {
                aux = rightList[i];
                rightList[i] = rightList[j];
                rightList[j] = aux;
            }
        }
    }

    // Solution for the first half. Get the distance between each location and add them

    for (int i = 0; i < length; i ++) {
        totalDistance += abs(rightList[i] - leftList[i]);
    }
    
    cout << "The total distance between the lists is: " << totalDistance << endl;
    
    // Solution for the second half. Get the score of each location and add them

    for (int i = 0; i < length; i ++) {
        int individualScore = 0;
        for (int j = 0; j < length; j ++) {
            if (leftList[i] == rightList[j]) {
                individualScore++;
            }
        }
        similarityScore += leftList[i] * individualScore;
    }

    cout << "The total similarity score is: " << similarityScore << endl;
}

vector<string> split(string input) {
    vector<string> returnValue;
    stringstream stream(input);
    string element;
    while (stream >> element) {
        returnValue.push_back(element);
    }
    stream.clear();
    return returnValue;
}