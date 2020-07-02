#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

class Mass {
public:
  void setMassAvoirdupoisPounds(double lbs) {
    Drams = (256.0)*lbs;
  }

  void setMassTroyPounds(double lbs) {
    Drams = (96.0)*lbs;
  }

  void setMassMetricGrams(double grams) {
    Drams = grams / 1.7718451953125;
  }
  
  double getMassAvoirdupoisPounds() {
    return Drams /256.0;
  }

  double getMassTroyPounds() {
    return Drams / 96.0;
  }

  double getMassMetricGrams() {
    return (Drams*1.7718451953125);
  }
  
private:
  double Drams;	
};


int main() {
  int status = 0;
  bool brk = false;
  int inp;
  Mass dram;
  while (brk == false) {
    while ((cout << "Please enter 1 to use Avoirdupois Pounds, 2 to use Troy Pounds, 3 to use grams, or 0 to exit:") && (!(cin >> inp) || inp > 3 || inp < 0)) {
      cout << "Please enter a valid number between 0-3." << endl;
      cin.clear();
      cin.ignore(numeric_limits <streamsize>::max(), '\n');
    }
    double input;

    switch (inp) {
    case 1:
      while ((cout << "Please enter a mass in Avordupois Pounds: ") &&
	     (!(cin >> input) || input < 0.0 || input  < NAN)) {
	cout << "Please enter a valid number between 0 and NAN." << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      dram.setMassAvoirdupoisPounds(input);
      cout << "Mass in Avoirdupois Pounds is: " << dram.getMassAvoirdupoisPounds() << endl
	   << "Mass in Troy Pounds is: " << dram.getMassTroyPounds() << endl
	   << "Mass in Metric Grams is : " << dram.getMassMetricGrams() << endl << endl;
      break;

    case 2:
      while ((cout << "Please enter a mass in Troy Pounds: ") &&
	     (!(cin >> input) || input < 0.0 || input  < NAN)) {
	cout << "Please enter a valid number between 0 and NAN." << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      dram.setMassTroyPounds(input);
      cout << "Mass in Avoirdupois Pounds is: " << dram.getMassAvoirdupoisPounds() << endl
	   << "Mass in Troy Pounds is: " << dram.getMassTroyPounds() << endl
	   << "Mass in Metric Grams is : " << dram.getMassMetricGrams() << endl << endl;
      break;

    case 3:
      while ((cout << "Please enter a mass in Metric Grams: ") &&
	     (!(cin >> input) || input < 0.0 || input  < NAN)) {
	cout << "Please enter a valid number between 0 and NAN." << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      dram.setMassMetricGrams(input);
      cout << "Mass in Avoirdupois Pounds is: " << dram.getMassAvoirdupoisPounds() << endl
	   << "Mass in Troy Pounds is: " << dram.getMassTroyPounds() << endl
	   << "Mass in Metric Grams is : " << dram.getMassMetricGrams() << endl << endl;
      break;

    default:
      brk = true;
      cout << "Thanks for using the mass conversion program!" << endl << endl;
      break;
    }
  }
  return status;
}
