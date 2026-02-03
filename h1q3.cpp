#include <iostream>
#include <iomanip>
using namespace std;
const double MONTHLY_RATE = 0.015;
const double PAYMENT = 50.0;

int main()
{
    double balance;
    cout << "Enter loan amount: ";
    cin >> balance;
    int month = 0;
    double interest, principal, paymentThisMonth;
    double totalInterest = 0.0;
    double totalPaid = 0.0;
    cout << setw(7) << "Month#"<< setw(12) << "Interest"<< setw(12) << "Principal"<< setw(12) << "Balance"<< setw(14) << "TotalInt"<< setw(14) << "TotalPaid"<< endl;
    cout << fixed << setprecision(2);
    while (balance > 0)
    {
        month++;
        interest = balance * MONTHLY_RATE;
        if (balance + interest <= PAYMENT)
            paymentThisMonth = balance + interest;
        else
            paymentThisMonth = PAYMENT;
        principal = paymentThisMonth - interest;
        balance = balance - principal;
        if (balance < 0.00001)
            balance = 0.0;
        totalInterest += interest;
        totalPaid += paymentThisMonth;
        cout << setw(7) << month<< setw(12) << interest<< setw(12) << principal<< setw(12) << balance<< setw(14) << totalInterest<< setw(14) << totalPaid<< endl;
    }

    return 0;
}
