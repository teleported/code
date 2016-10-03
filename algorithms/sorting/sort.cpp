#include <iostream>
#include <vector>

template <typename T>
bool less(const T& left, const T& right)
{
    return left < right;
}

template <typename T>
bool swap(T& left, T& right)
{
    T temp = left;
    left = right;
    right = temp;
}



int main()
{
    
    return 0;
}
