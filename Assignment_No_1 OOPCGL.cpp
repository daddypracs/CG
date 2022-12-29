/*Problem Statement:
Implement a class Complex which represents the Complex Number data type. Implement the following operations:
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >> to print and read Complex Numbers.*/

#include <iostream>
using namespace std;

class complex
{
	float real;
	float img;
public:
	complex()
	{
		real = 0.0;
		img = 0.0;
	}

	friend istream& operator >>(istream& i, complex& O)
	{
		cout << "Enter real part:" << endl;
		i >> O.real;
		cout << "Enter imaginary part:" << endl;
		i >> O.img;
		return i;
	}
	friend ostream& operator <<(ostream& c, complex& O)
	{
		c << O.real << " + " << O.img << "i" << endl;
		return c;
	}
	complex operator +(complex O)
	{
		complex r1;
		r1.real = real + O.real;
		r1.img = img + O.img;
		return r1;
	}
	complex operator -(complex O)
	{
		complex r2;
		r2.real = real - O.real;
		r2.img = img - O.img;
		return r2;
	}
	complex operator*(complex O)
	{
		complex r3;
		r3.real = (real * O.real) - (img * O.img);
		r3.img = (real * O.img) + (img * O.real);
		return r3;
	}
};
int main()
{
	complex c1, c2, c3;
	int choice;
	char ans;
	cout << "Default constructor value=" << endl;
	cout << c1;
	do
	{
		cout << "\nEnter the 1st no." << endl;
		cin >> c1;
		cout << "\nEnter the 2nd no." << endl;
		cin >> c2;
		cout << "1. Addition" << endl;
		cout << "2. Subtraction" << endl;
		cout << "3. Multiplication" << endl;
		cout << "Enter Choice:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			c3 = c1 + c2;
			cout << "Addition is: " << endl;
			cout << c3;
			break;
		case 2:
			c3 = c1 - c2;
			cout << "Subtraction is: " << endl;
			cout << c3;
			break;
		case 3:
			c3 = c1 * c2;
			cout << "Multiplication is: " << endl;
			cout << c3;
			break;
		default:
			cout << "Wrong Choice:" << endl;
		};
		cout << "Do you want to Continue?(y/n):" << endl;
		cin >> ans;

	} while (ans == 'y' || ans == 'Y');
	return 0;
}
