#include <iostream>
using namespace std;
// variables
int totalSeconds;
int hours;
int minutes;
int seconds;
double hoursReal;
double minutesReal;

int main()
{
    // ask for input
    cout << "Enter the number of seconds: ";
    cin >> totalSeconds;

    // calculate
    hours = totalSeconds / 3600;
    minutes = (totalSeconds % 3600) / 60;
    seconds = totalSeconds % 60;
    hoursReal = totalSeconds / 3600.0;
    minutesReal = totalSeconds / 60.0;
    hoursReal = (int)(hoursReal * 10000) / 10000.0;
    minutesReal = (int)(minutesReal * 10000) / 10000.0;
    
    // out
    cout << hours << " hours, "
         << minutes << " minutes, "
         << seconds << " seconds" << endl;
    cout << hoursReal << " hours" << endl;
    cout << minutesReal << " minutes" << endl;

    return 0;
}
