#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
  int intRate, numberOfMonths;
  double annualInterestRate, amountToReceive, numberOfYears, faceValue;
  
  do {
    cout << "Please enter the annual interest rate as a percentage (e.g., 15 for 15%) (enter 0 to Quit): ";
    cin >> intRate;
    
    if (intRate == 0) {
      exit(0);
    }

    annualInterestRate = intRate / 100.0;
    cout << "Please enter the amount you would like to receive: ";
    cin >> amountToReceive;
    cout << "Please enter loan period in months: ";
    cin >> numberOfMonths;
    
    numberOfYears = numberOfMonths / 12.0;
    
    faceValue = amountToReceive / (1 - annualInterestRate * numberOfYears);
    
    cout << "The total amount of your loan (including interest at " << intRate
	 << "% per annum) is $" << fixed << setprecision(2) << faceValue << "." << endl;
    
    cout << "Your monthly payment for " << numberOfMonths << " months will be $"
	 << fixed << setprecision(2) << faceValue / numberOfMonths << "." << endl << endl;
  } while (1);
  
  return 0;
}
