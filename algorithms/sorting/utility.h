#ifndef __UTILITY_H_
#define __UTILITY_H_

#include <ctime>
#include <vector>

using namespace std;

template <typename T>
bool validate(typename vector<T>::iterator start, typename vector<T>::iterator end) {
    while(start != (end-1)) {
        T a = *start;
        T b = *(start+1);
        if(a > b)
            return false;
        start++;
    }
    return true;
}

double diffclock_ms(clock_t clock1,clock_t clock2)
{
    double diffticks=clock2-clock1;
    double diffms=(diffticks)/(CLOCKS_PER_SEC/1000);
    return diffms;
}

#endif // __UTILITY_H_
