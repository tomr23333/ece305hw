#include <iostream>
using namespace std;

void initialize_board(char board[3][3]){
    char num = '1';
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = num;
            num++;
        }
    }
}

void display_board(char board[3][3]){
    cout << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool valid_move(char board[3][3], int position){
    if(position < 1 || position > 9){
        return false;
    }
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if(board[row][col] == 'X' || board[row][col] == 'O'){
        return false;
    }
    return true;
}

void place_move(char board[3][3], int position, char player){
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    board[row][col] = player;
}

bool check_winner(char board[3][3], char player){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return true;
        }
    }

    for(int j = 0; j < 3; j++){
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player){
            return true;
        }
    }

    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return true;
    }

    if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return true;
    }

    return false;
}

bool board_full(char board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != 'X' && board[i][j] != 'O'){
                return false;
            }
        }
    }
    return true;
}

int main(){
    char board[3][3];
    char player = 'X';
    int position;

    initialize_board(board);
    display_board(board);

    while(true){
        cout << "Player " << player << ", position: ";
        cin >> position;
        while(valid_move(board, position) == false){
            cout << "wrong move. enter again: ";
            cin >> position;
        }

        place_move(board, position, player);
        display_board(board);

        if(check_winner(board, player)){
            cout << "player " << player << " wins" << endl;
            break;
        }

        if(board_full(board)){
            cout << "draw game" << endl;
            break;
        }

        if(player == 'X'){
            player = 'O';
        }
        else{
            player = 'X';
        }
    }

    return 0;
}