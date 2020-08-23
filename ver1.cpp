
#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
typedef complex<double> dcomp;

dcomp f(dcomp y, dcomp x); //declare the function for the given equation
dcomp f(dcomp y, dcomp x)  //define the function here, ie give the equation
{
  dcomp i;
  i = -1;
  i = sqrt(i);
  dcomp weg = 4, rho = 0.1;
  dcomp a = (pow(y, 2)) * (tanh(x + i * y)) - (rho * pow(x, 2)) + (rho / weg) * (pow((x + i * y), 3)); //write the equation whose roots are to be determined
  return a;
}
dcomp fprime(dcomp y, dcomp x);
dcomp fprime(dcomp y, dcomp x)
{
  dcomp i;
  ;
  i = -1;
  i = sqrt(i);
  dcomp weg = 4, rho = 0.1;
  dcomp za = 2, zb = 3;
  dcomp b = zb * i * (rho / weg) * pow((x + i * y), 2) + i * pow((y / cosh(x + i * y)), 2) + za * y * tanh(x + i * y);
  return b;
}

main()
{
  cout.precision(4);
  cout.setf(ios::fixed);

  ofstream outData;
  outData.open("final.csv", ios::app);
  dcomp y1, y;
  dcomp z = 2, f_up, fz_up;
  dcomp finx[51];
  cout << "enter initial guess" << endl;
  cin >> y1;
  double e = 0.01;
  int s = 0;
  dcomp x = 0;
  int t;
  for (t = 0; t < 500; t++)
  {
    x = x + 0.01;
    f_up = f(y, x);
    fz_up = fprime(y, x);
    int iter = 1;
    dcomp err;
    do
    {
      y = y1;
      f_up = f(y, x);
      fz_up = fprime(y, x);
      y1 = y - (f_up / fz_up);
      iter++;
      err = y1 - y;
    } while (fabs(err) >= e);

    cout << x << "   ";
    cout << y << endl;
    cout << t;
    outData << -1 * y.imag() << endl;
    s = s + 1;
    //cout << s << endl;
  }
  return 0;
}