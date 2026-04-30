#include <iostream>
#include <vector>
using namespace std;

void deleteRepeatedChars(vector<char>& myVector){
    for (int i = 0; i < myVector.size(); i++){
        for (int j = i + 1; j < myVector.size(); j++){
            if (myVector[i] == myVector[j]){
                for (int k = j; k < myVector.size() - 1; k++){
                    myVector[k] = myVector[k + 1];
                }
                myVector.pop_back(); 
                j--;
            }
        }
    }
}


void selectionSort(vector<char>& myVector){
    for (int i = 0; i < myVector.size(); i++){
        int maxIndex = i;

        for (int j = i + 1; j < myVector.size(); j++){
            if (myVector[j] > myVector[maxIndex]){
                maxIndex = j;
            }
        }
        char temp = myVector[i];
        myVector[i] = myVector[maxIndex];
        myVector[maxIndex] = temp;
    }
}


void getInput(vector<char>& myVector)
{
    char ch;
    cout << "characters" << endl;
    cin >> ch;
    while (ch != '0'){
        myVector.push_back(ch);
        cin >> ch;
    }
}


void printVector(vector<char> myVector){
    for (int i = 0; i < myVector.size(); i++){
        cout << myVector[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<char> myVector;
    getInput(myVector);
    deleteRepeatedChars(myVector);
    selectionSort(myVector);
    printVector(myVector);
    return 0;
}