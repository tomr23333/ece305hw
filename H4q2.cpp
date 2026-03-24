#include <iostream>
using namespace std;

//difficulty
double getdifficulty(){
    double diff;
    cout << "Enter difficulty (1.2 - 3.8): ";
    cin >> diff;

    while(diff < 1.2 || diff > 3.8){
        cout << "1.2 - 3.8: ";
        cin >> diff;
    }

    return diff;
}

//input 7 scor
void get_scores(double scores[], int size){
    cout << "Enter 7 scores :" << endl;
    for(int i = 0; i < size; i++){
        do{
            cin >> scores[i];
        } while(scores[i] < 0 || scores[i] > 10);
    }
}

// look for maximum
double find_max(double scores[], int size){
    double max = scores[0];
    for(int i = 1; i < size; i++){
        if(scores[i] > max){
            max = scores[i];
        }
    }
    return max;
}

// find minnimum
double find_min(double scores[], int size){
    double min = scores[0];
    for(int i = 1; i < size; i++){
        if(scores[i] < min){
            min = scores[i];
        }
    }
    return min;
}

// score calculates
double calculate_score(double scores[], int size, double difficulty){
    double max = find_max(scores, size);
    double min = find_min(scores, size);
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum += scores[i];
    }
    sum = sum - max - min;
    double final_score = sum * difficulty * 0.6;
    return final_score;
    
}

// output
void display(double result){
    cout << "Score: " << result << endl;
}


int main(){
    double scores[7];
    double difficulty;
    difficulty = getdifficulty();
    get_scores(scores, 7);
    double result = calculate_score(scores, 7, difficulty);
    display(result);
    return 0;
}