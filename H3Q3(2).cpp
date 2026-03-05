#include <iostream>
using namespace std;
int minutes_between(int start_time, int end_time);
int main(){
    int start_time;
    int end_time;
    int minutes;
    cout << "Enter start time : ";
    cin >> start_time;
    cout << "Enter end time : ";
    cin >> end_time;
    minutes = minutes_between(start_time, end_time);
    cout << "Minutes between times: " << minutes << endl;
    return 0;
}

int minutes_between(int start_time, int end_time){
    int start_hour;
    int start_min;
    int end_hour;
    int end_min;
    int start_total;
    int end_total;
    int difference;
    start_hour = start_time / 100;
    start_min = start_time % 100;
    end_hour = end_time / 100;
    end_min = end_time % 100;

    start_total = start_hour * 60 + start_min;
    end_total = end_hour * 60 + end_min;

    if (end_total >= start_total){
        difference = end_total - start_total;
    }
    else{
        difference = (1440 - start_total) + end_total;
    }
    return difference;
}