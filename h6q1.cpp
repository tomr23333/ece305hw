#include <iostream>
#include <vector>
using namespace std;

void get_numbers(vector<int>& numbers){
    int num;
    cout << "integers" << endl;
    cin >> num;
    while (num >= 0){
        numbers.push_back(num);
        cin >> num;
    }
}

int find_max(vector<int> numbers){
    int max = numbers[0];
    for (int i = 0; i < numbers.size(); i++){
        if (numbers[i] > max){
            max = numbers[i];
        }
    }

    return max;
}

void make_histogram(vector<int> numbers, vector<int>& bins){
    int bin_number;

    for (int i = 0; i < numbers.size(); i++){
        bin_number = numbers[i] / 10;
        bins[bin_number]++;
    }
}

void print_histogram(vector<int> bins){
    for (int i = 0; i < bins.size(); i++){
        cout << i * 10 << " - " << i * 10 + 9 << ": " << bins[i] << endl;
    }
}

int main(){
    vector<int> numbers;
    get_numbers(numbers);
    if (numbers.size() == 0){
        return 0;
    }

    int max = find_max(numbers);
    int bin_size = max / 10 + 1;
    vector<int> bins(bin_size);
    make_histogram(numbers, bins);
    print_histogram(bins);
    return 0;
}