#include <iostream>
using namespace std;
void get_input(double& lb, double& oz);
void convert_weight(double lb, double oz, int& kg, int& g);
void output_weight(int kg, int g);
int main(){
    double lb;
    double oz;
    int kg;
    int g;
    while (true){
        get_input(lb, oz);
        if (lb < 0){
            break;
        }
        convert_weight(lb, oz, kg, g);
        output_weight(kg, g);
    }

    return 0;
}
void get_input(double& lb, double& oz){
    cout << "Enter lb: ";
    cin >> lb;
    if (lb < 0){
        return;
    }
    cout << "Enter oz: ";
    cin >> oz;
}

void convert_weight(double lb, double oz, int& kg, int& g){
    double total_lb;
    double total_kg;
    double total_g;
    total_lb = lb + (oz / 16.0);
    total_kg = total_lb / 2.2046;
    total_g = total_kg * 1000;
    kg = total_g / 1000;
    g = total_g - (kg * 1000);
}

void output_weight(int kg, int g){
    cout << "Equivalent weight: ";
    cout << kg << " kg " << g << " g" << endl;
}