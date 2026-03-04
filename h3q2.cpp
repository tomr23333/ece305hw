#include <iostream>
#include <cmath>
using namespace std;
void triangle_info(double a, double b, double c, double& area, double& perimeter);
int main(){
    double a, b, c;
    double area, perimeter;
    while (true){
        cout << "Enter side a (negative to quit): ";
        cin >> a;
        if (a < 0)
        {
            break;
        }
        cout << "Enter side b: ";
        cin >> b;

        cout << "Enter side c: ";
        cin >> c;
        triangle_info(a, b, c, area, perimeter);
        cout << "Perimeter: " << perimeter << endl;
        cout << "Area: " << area << endl;
        cout << endl;
    }

    return 0;
}
void triangle_info(double a, double b, double c, double& area, double& perimeter){
    if (a > 0 && b > 0 && c > 0 &&
        a + b > c &&
        a + c > b &&
        b + c > a){
        perimeter = a + b + c;
        double s = perimeter / 2.0;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
    }
    else
    {
        area = 0;
        perimeter = 0;
    }
}