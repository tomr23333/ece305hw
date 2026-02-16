#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    ifstream inFile("scores.txt");
    ofstream outFile("output.txt");
    double scores[5];
    double sum = 0;
    double average;
    double variance = 0;
    double stdDev;
    // read
    for (int i = 0; i < 5; i++){
        inFile >> scores[i];
        sum += scores[i];
    }

    // avg
    average = sum / 5;

    // standerdevation
    for (int i = 0; i < 5; i++){
        variance += pow(scores[i] - average, 2);
    }
    stdDev = sqrt(variance / 5);
    cout << fixed << setprecision(2);
    outFile << fixed << setprecision(2);
    // output
    cout << "Average: " << average << endl;
    cout << "Standard Deviation: " << stdDev << endl;
    // save to file
    outFile << "Average: " << average << endl;
    outFile << "Standard Deviation: " << stdDev << endl;

    inFile.close();
    outFile.close();
    return 0;
}
