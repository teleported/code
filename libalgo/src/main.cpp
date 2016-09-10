#include <iostream>
#include "includes.h"

int main()
{
    using namespace std;

    cout << "gcd():" << endl;
    cout << "gcd(10, 5) = " << gcd(10, 5) << endl; 
    cout << "gcd(5, 10) = " << gcd(5, 10) << endl; 
    cout << "gcd(9, 10) = " << gcd(9, 10) << endl; 
    cout << "gcd(8, 10) = " << gcd(8, 10) << endl; 
    return 0;
}
