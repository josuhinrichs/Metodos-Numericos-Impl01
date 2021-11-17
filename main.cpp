#include <iostream>
#include <cmath>
using namespace std;

long double fun (long double d, long double a) {
    const double e = std::exp(1.0);
    long double res = a*pow(e, d) - 4*pow(d, 2);
    return res;
}

long double der (long double d, long double a) {
    const double e = std::exp(1.0);
    long double res = a*pow(e, d) - 8*d;
    return res;
}

void nr (long double x0, long double a, long double e1, long double e2, int iterMax) {

    cout << x0 << '\n';
    long double raiz;
    
    if ( abs(fun(x0, a)) < e1) { raiz = x0; return; }
    int k = 1;

    long double x1;

    cout << x0 << '\n';

    while (true){

        x1 = x0 - fun(x0, a)/der(x0, a);
        cout.precision(15);
        cout << "k: " << k << " x1: " << x1 << " x0: " << x0 << " x1-x0: " << x1 - x0 << " f(x1): " << fun(x1,a) << '\n';
        if ( abs(fun(x1, a)) < e1 or abs(x1-x0) < e2 or k >= iterMax) { raiz = x1; break; }
        x0 = x1;
        k++;
    }
}

int main(){
    nr( 5, 1, pow(10, -4), pow(10, -4), 1000);
}