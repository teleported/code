#include <fstream>
#include <iostream>
#include <vector>
#include "sort.h"

using namespace std;


template <typename T>
bool isSorted(const vector<T>& list)
{

    size_t size = list.size();

    for(int i = 0; i < (size-1); ++i) {
        if(list[i] > list[i+1])
            return false;
    }

    return true;
}

void load_ints(vector<int>& list)
{
    ifstream f("../data/random_ints.txt");

    int i;
    while(f >> i) {
        list.push_back(i);
    }
    f.close();
}


int main()
{

    // Initialize infra
    vector<int> v;
    load_ints(v);
    size_t size = v.size();
    cout << "Sorting " << size << " items" << endl;

    // Before sort
    if(size == v.size() && isSorted(v)) 
        cout << "Before: Sorted" << endl;
    else
        cout << "Before: Not Sorted" << endl;

    // Sort
    Selection<int> s;
    s.sort(v);

    // Verity
    if(size == v.size() && isSorted(v)) 
        cout << "After: Sorted" << endl;
    else
        cout << "After: Not Sorted" << endl;
    return 0;
}
