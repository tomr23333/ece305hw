#include <iostream>
using namespace std;

// initialize seats
void initialize_seats(char seats[][4], int rows){
    for(int i = 0; i < rows; i++){
        seats[i][0] = 'A';
        seats[i][1] = 'B';
        seats[i][2] = 'C';
        seats[i][3] = 'D';
    }
}

// display seats
void display_seats(char seats[][4], int rows){
    cout << endl;
    for(int i = 0; i < rows; i++){
        cout << i + 1 << "    ";
        for(int j = 0; j < 4; j++){
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// change seat letter to column number
int find_column(char seat_letter){
    if(seat_letter == 'A'){
        return 0;
    }
    else if(seat_letter == 'B'){
        return 1;
    }
    else if(seat_letter == 'C'){
        return 2;
    }
    else if(seat_letter == 'D'){
        return 3;
    }
    else{
        return -1;
    }
}



// check if seat is available
bool seat_available(char seats[][4], int row, int col){
    if(seats[row][col] == 'X'){
        return false;
    }
    else{
        return true;
    }
}

// assign seat
void assign_seat(char seats[][4], int row, int col){
    seats[row][col] = 'X';
}

// check if all seats are taken
bool all_taken(char seats[][4], int rows){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < 4; j++){
            if(seats[i][j] != 'X'){
                return false;
            }
        }
    }
    return true;
}

// get valid seat input
void get_seat_choice(char seats[][4], int rows, int& row_number, char& seat_letter){
    int col;
    cout << "Enter seat number: ";
    cin >> row_number;
    cout << "seat letter A, B, C, D: ";
    cin >> seat_letter;

    while(true){
        col = find_column(seat_letter);
        if(row_number < 1 || row_number > 10 || col == -1){
            cout << "seat row number: ";
            cin >> row_number;
            cout << "seat letter A, B, C, D: ";
            cin >> seat_letter;
        }
        else if(seat_available(seats, row_number - 1, col) == false){
            cout << "seat taken." << endl;
            cout << "seat number: ";
            cin >> row_number;
            cout << "seat letter: "<<endl;
            cin >> seat_letter;
        }
        else{
            break;
        }
    }
}

int main(){
    char seats[10][4];
    char choice = 'Y';
    int row_number;
    char seat_letter;
    int col;
    initialize_seats(seats, 10);
    while(choice == 'Y' || choice == 'y'){
        display_seats(seats, 10);
        if(all_taken(seats, 10)){
            cout << "no seat." << endl;
            break;
        }
        get_seat_choice(seats, 10, row_number, seat_letter);
        col = find_column(seat_letter);
        assign_seat(seats, row_number - 1, col);
        display_seats(seats, 10);
        if(all_taken(seats, 10)){
            cout << "no seat." << endl;
            break;
        }
        cout << "adding more? Y/N: ";
        cin >> choice;
    }

    return 0;
}