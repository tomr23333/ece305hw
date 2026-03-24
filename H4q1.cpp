#include <iostream>
using namespace std;
// input data
void input(int arr[], int size){
    cout << "Enter " << size << " non-negative integers:" << endl;
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
}

// looking for max
int find_max(int arr[], int size){
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

// histogram
void histogram(int arr[], int size, int bins[], int bin_size){
    for(int i = 0; i < size; i++)
    {
        int index = arr[i] / 10;  
        bins[index]++;
    }
}

// output Histogram
void display_histogram(int bins[], int bin_size){
    cout << "\nHistogram:\n";
    for(int i = 0; i < bin_size; i++){
        cout << i*10 << " - " << i*10+9 << " : " << bins[i] << endl;
    }
}

int main(){
    int size;
    cout << "Enter number of elements: ";
    cin >> size;
    int arr[100];   
    input(arr, size);



    int max = find_max(arr, size);
    int bin_size = max / 10 + 1;
    int bins[100] = {0};   
    histogram(arr, size, bins, bin_size);
    display_histogram(bins, bin_size);
    return 0;
}