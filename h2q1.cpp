#include <iostream>
#include <cmath>
using namespace std;
int main(){
    const double G = 6.673e-8;   // gravitational constant
    char repeat; 
    do{
        double m1, m2, d;
        double F;
        cout << "Enter mass m1 (in grams): ";
        cin >> m1;
        cout << "Enter mass m2 (in grams): ";
        cin >> m2;
        cout << "Enter distance d (in cm): ";
        cin >> d;
        F = (G * m1 * m2) / pow(d, 2);
        cout << "Gravitational Force = " << F << " dynes" << endl;
        cout << "Do you want to calculate again? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');
    return 0;
}