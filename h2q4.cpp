#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main(){
    srand(time(0));   
    int winners[4];
    int count = 0;

    while (count < 4)
    {
        int num = rand() % 25 + 1;   

        bool duplicate = false;
        for (int i = 0; i < count; i++){
            if (winners[i] == num)
            {
                duplicate = true;
                break;
            }
        }
        if (!duplicate)
        {
            winners[count] = num;
            count++;
        }
    }
    cout << "The 4 winners are: ";
    for (int i = 0; i < 4; i++){
        cout << winners[i] << " ";
    }

    cout << endl;
    return 0;
}
