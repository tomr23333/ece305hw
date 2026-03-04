#include <iostream>
using namespace std;

void get_input(int& hour24, int& minute);
void convert_time(int& hour12, int minute, char& am_pm);
void output_time(int hour12, int minute, char am_pm);
int main(){
	int hour24;
	int minute;

	while (true){
		get_input(hour24, minute);
		if (hour24 < 0 || minute < 0){
			break;
		}
		int hour12 = hour24;
		char am_pm;
		convert_time(hour12, minute, am_pm);
		output_time(hour12, minute, am_pm);
	}

	return 0;
}

void get_input(int& hour24, int& minute)
{
	cout << "Enter hour (0-23). Enter a negative number to stop: ";
	cin >> hour24;

	cout << "Enter minute (0-59). Enter a negative number to stop: ";
	cin >> minute;
}

void convert_time(int& hour12, int minute, char& am_pm){
	if (hour12 == 0){
		hour12 = 12;
		am_pm = 'A';
	}
	else if (hour12 < 12){
		am_pm = 'A';
	}
	else if (hour12 == 12){
		am_pm = 'P';
	}
	else{
		hour12 = hour12 - 12;
		am_pm = 'P';
	}
}
void output_time(int hour12, int minute, char am_pm)
{
	cout << "12-hour time: ";
	cout << hour12 << ":";
	if (minute < 10)
	{
		cout << 0;
	}
	cout << minute << " ";

	if (am_pm == 'A')
	{
		cout << "AM";
	}
	else
	{
		cout << "PM";
	}

	cout << endl;
}