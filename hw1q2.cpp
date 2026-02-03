#include <iostream>
using namespace std;
// Constant
const double PAY_RATE = 36.75;
const double OVERTIME_RATE = 1.5;
const double SOCIAL_SECURITY = 0.06;
const double FEDERAL_TAX = 0.15;
const double STATE_TAX = 0.04;
const double UNION_DUES = 0.01;
const double HEALTH_INSURANCE = 40.0;
// variables
double hoursWorked;
int dependents;
double regularHours;
double overtimeHours;
double grossPay;
double totalDeductions;
double netPay;
int main()
{//input
    cout << "Enter hours worked: ";
    cin >> hoursWorked;

    cout << "Enter number of dependents: ";
    cin >> dependents;
    // Calculate regular working hours and overtime hours.
    if (hoursWorked <= 40)
    {regularHours = hoursWorked;
        overtimeHours = 0;}
    else
    {regularHours = 40;
    overtimeHours = hoursWorked - 40;}
    // Calculate total salary
    grossPay = (regularHours * PAY_RATE) +
               (overtimeHours * PAY_RATE * OVERTIME_RATE);
    //Calculate the deduction.
    totalDeductions = grossPay * (SOCIAL_SECURITY + FEDERAL_TAX +
                                  STATE_TAX + UNION_DUES);
    if (dependents >= 2)
    {totalDeductions = totalDeductions + HEALTH_INSURANCE;}
    // Calculate net salary
    netPay = grossPay - totalDeductions;
    grossPay = (int)(grossPay * 100) / 100.0;
    totalDeductions = (int)(totalDeductions * 100) / 100.0;
    netPay = (int)(netPay * 100) / 100.0;

    // output
    cout << "Gross pay: " << grossPay << endl;
    cout << "Total deductions: " << totalDeductions << endl;
    cout << "Net pay: " << netPay << endl;

    return 0;
}
