//Secant Method for finding the roots of an equation
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;
double f(double x); //declare the function for the given equation
double f(double x)  //define the function here, ie give the equation
{
    double a = x * x - 2.0 * x - 5.0; //write the equation whose roots are to be determined
    return a;
}
int main()
{
    cout.precision(6);
    cout.setf(ios::fixed); //set the precision of the output
    double a, b, c, e;
    int iter = 1;
    cout << "Enter the initial guess\na=";
    cin >> b;
    cout << "b="; //take an initial guess
    cin >> c;
    cout << "Enter the degree of accuracy\n";
    cin >> e; //take the desired accuracy
    cout << "Iter" << setw(12) << "a" << setw(12) << "b" << setw(12) << "c" << setw(12) << "f(c)" << setw(12) << "|cnc|" << endl;

    do
    {
        a = b;
        b = c;                                  //make b equal to the last calculated value of c
        c = b - (b - a) / (f(b) - f(a)) * f(b); //calculate c
        cout << iter << setw(16) << a << setw(12) << b << setw(12) << c << setw(12) << f(c) << setw(12) << fabs(c - b) << endl;
        if (f(c) == 0)
        {
            cout << "\nThe root of the equation is " << c; //print the root
            return 0;
        }
        iter++;
    } while (abs(c - b) > e);                              //check if the error is greater than the desired accuracy
    cout << "\nThe root of the equation is " << c << endl; //print the root
    return 0;
}