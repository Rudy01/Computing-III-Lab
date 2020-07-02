#include <iostream>
#include <math.h>
#include <limits>
#include <iomanip>
using namespace std;

void GetInput(int &pound, double &ounce) {   
  while((cout <<"Please enter the number of pounds:")&&(!(cin >> pound)|| pound<0)){
    cout << "That's not a number greater than or equal to 0! Please try again..." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  }
  
  while((cout <<"Please enter the number of ounces:")&&(!(cin >> ounce)|| !((ounce>=0)&&(ounce<=16)))){
    cout << "That's not a number greater than or equal to 0, and less than 16! Please try again..." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  }
}

void weightCalculating(int &pound, double &ounce, double &kilograms, double &grams) {
  double combiner;
  combiner = 1.0 * pound + ounce / 16.0;
  kilograms = 0.45359237 * combiner;
  double Onlykilograms = floor(kilograms);
  grams = (kilograms - Onlykilograms)*1000.0;  
}

void weightOutput(int &pound, double &ounce, double &kilograms, double &grams) {
  cout << pound << " pounds and " <<fixed<<setprecision(8)<< ounce <<
    " ounces are converted into " << int(floor(kilograms)) <<" kilograms and "<<fixed<<setprecision(8) <<grams << " grams";
}

int main() {   
  int pound = 0;
  double ounce = 0.0;
  double kilograms;
  double grams;
  GetInput(pound, ounce);
  weightCalculating(pound, ounce, kilograms, grams);
  weightOutput(pound, ounce, kilograms, grams);
  return 0;
}
