//Newton-Raphson Method
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
double f(double x); //declare the function for the given equation
double f(double x)  //define the function here, ie give the equation
{
    double a = 3.0 * x + sin(x) - pow(2.71828, x); //write the equation whose roots are to be determined
    return a;
}
double fprime(double x);
double fprime(double x)
{
    double b = 3.0 + cos(x) - pow(2.71828, x); //write the first derivative of the equation
    return b;
}
int main()
{
    double x, x1, e, fx, fx1;
    cout.precision(4); //set the precision
    cout.setf(ios::fixed);
    cout << "Enter the initial guess\n"; //take an intial guess
    cin >> x1;
    cout << "Enter desired accuracy\n"; //take the desired accuracy
    cin >> e;
    fx = f(x);
    fx1 = fprime(x);
    int iter = 1;
    cout << "iter" << setw(8) << "x{i}" << setw(19) << "x{i+1}" << setw(19) << "|x{i+1}-x{i}|" << endl;
    cout << "--------------------------------------------------------------\n"; //to make a line on the screen for
                                                                                //formatted and clean output

    do
    {
        x = x1;              /*make x equal to the last calculated value of x1*/
        fx = f(x);           //simplifying f(x)to fx
        fx1 = fprime(x);     //simplifying fprime(x) to fx1
        x1 = x - (fx / fx1); /*calculate x{1} from x, fx and fx1*/
        cout << iter << setw(12) << x << setw(16) << x1 << setw(16) << abs(x1 - x) << endl;
        iter++;
    } while (fabs(x1 - x) >= e); /*if |x{i+1}-x{i}| remains greater than the desired accuracy, continue
the loop*/
    cout << "The root of the equation is " << x1 << endl;
    return 0;
}
