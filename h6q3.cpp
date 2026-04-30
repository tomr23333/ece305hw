#include <iostream>
#include <vector>
using namespace std;
void findPrime(vector<int>& prime, int n){
    for (int i = 0; i < n; i++){
        prime.push_back(1);
    }

    prime[0] = 0;
    prime[1] = 0;

    for (int i = 2; i < n; i++){
        if (prime[i] == 1){
            for (int j = i * 2; j < n; j = j + i){
                prime[j] = 0;
            }
        }
    }
}

void printPrime(vector<int> prime)
{
    cout << "prime numbers" << endl;
    for (int i = 0; i < prime.size(); i++)
    {
        if (prime[i] == 1)
        {
            cout << i << " ";
        }
    }

    cout << endl;
}

int main(){
    int n;
    vector<int> prime;
    cout << "number:";
    cin >> n;
    if (n <= 2){
        return 0;
    }

    findPrime(prime, n);
    printPrime(prime);
    return 0;
}