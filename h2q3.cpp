#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double height, weight;
    int age;

    cout << "Enter height (in inches): ";
    cin >> height;

    cout << "Enter weight (in pounds): ";
    cin >> weight;

    cout << "Enter age (in years): ";
    cin >> age;

    // 1) Hat
    double hat = 2.9 * (weight / height);

    // 2) Jacket (base + adjustment)
    double jacket = (height * weight) / 288.0;
    if (age > 30) {
        int tensOver30 = (age - 30) / 10;          
        jacket += tensOver30 * (1.0 / 8.0);        
    }

    // 3) Waist (base + adjustment)
    double waist = weight / 5.7;
    if (age > 28) {
        int twosOver28 = (age - 28) / 2;          
        waist += twosOver28 * 0.1;                
    }

    // neat output
    cout << fixed << setprecision(2);
    cout << "\n--- Clothing Sizes ---\n";
    cout << "Hat size   : " << hat << endl;
    cout << "Jacket size: " << jacket << " inches" << endl;
    cout << "Waist size : " << waist << " inches" << endl;

    return 0;
}
