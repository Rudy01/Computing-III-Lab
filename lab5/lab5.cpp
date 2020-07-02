// Examples of constructors, overloading, & friend functions/classes
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ComplexNumber {
    public:
        ComplexNumber() : _real(0.0), _imag(0.0) {}
    
        ComplexNumber( double r, double i ) : _real(r), _imag(i) {}
    
        // accessor functions
        double Re() { return _real; }
        double Im() { return _imag; }
    
        // mutator functions
        void setRe( double r ) { _real = r; }
        void setIm( double i ) { _imag = i; }
		
		// arithmetic operators
		ComplexNumber operator+ (ComplexNumber) const;
		ComplexNumber operator- (ComplexNumber) const;
		ComplexNumber operator* (ComplexNumber) const;
		ComplexNumber operator/ (ComplexNumber) const;
		
		// complex conjugate (represented by overloaded logical NOT operator)
		ComplexNumber operator! () const {
			return ComplexNumber(this->_real, -this->_imag);
		}
    
    friend ostream& operator<< (ostream&, ComplexNumber&);
    
    private:
        double _real, _imag;
};

// Note that these do NOT return a reference, so that the return value is copied into the calling context!

ComplexNumber ComplexNumber::operator+ (ComplexNumber c2) const {
		return ComplexNumber(this->_real+c2._real, this->_imag+c2._imag);
}
	
ComplexNumber ComplexNumber::operator- (ComplexNumber c2) const {
    return ComplexNumber(this->_real-c2._real, this->_imag-c2._imag);
}

ComplexNumber ComplexNumber::operator* (ComplexNumber c2) const {
    return ComplexNumber(this->_real*c2._real-this->_imag*c2._imag, this->_imag*c2._real+this->_real*c2._imag);
}

ComplexNumber ComplexNumber::operator/ (ComplexNumber c2) const {
	double d = c2._real*c2._real + c2._imag*c2._imag;
    return ComplexNumber((this->_real*c2._real+this->_imag*c2._imag)/d,
						 (this->_imag*c2._real-this->_real*c2._imag)/d);
}

// Definition of non-member friend function
ostream& operator<< (ostream& out, ComplexNumber& c) {
    out << c._real << "+" << c._imag << 'i';
    return out;
}

int main(void)
{
    ComplexNumber c1, c2(1.0, 2.0), c3(3.0, 4.0);
    
	cout << "c1.Re() == " << c1.Re() << ", c1.Im() == " << c1.Im() << endl;
    cout << "c2.Re() == " << c2.Re() << ", c2.Im() == " << c2.Im() << endl;
    
    c1 = c2 + c3;
    cout << c2 << " + " << c3 << " == " << c1 << endl << endl;
	
	c1 = c2 - c3;
    cout << c2 << " - " << c3 << " == " << c1 << endl << endl;	
	
	c1 = c2 * c3;
    cout << c2 << " * " << c3 << " == " << c1 << endl << endl;
	
	c1 = c2 / c3;
    cout << c2 << " / " << c3 << " == " << c1 << endl << endl;
	
	c1 = (c2/c3) + (c2*c3);
    cout << "(c2/c3) + (c2*c3) == " << c1 << endl << endl;
	
	c1 = !c2;
	cout << "Conjugate of c2 (" << c2 << ") == " << c1 << endl << endl;
	
	vector<ComplexNumber> vc;
	for (int i = 0; i < 10; i++) {
		vc.push_back(ComplexNumber(i, 2*i));
	}
	
	cout << "Vector output using indexed for-loop:\n";
	for (int i = 0; i < 10; i++) {
		cout << vc[i] << endl;
	}
	
	cout << "\nVector output using an iterator in for-loop:\n";
	// Type of it is actually std::vector<int>::iterator
	for (auto it = vc.begin(); it != vc.end(); ++it) {
		cout << *it << endl;
	}
    
    return 0;
}