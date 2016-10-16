/*
 * Best:    
 * Worst:   
 * Average: 
 *
 * Recursive algorithm
 * Divide and Conquer
 * Takes at most NlogN compares and 6NlogN array acesses
 * Online:  No
 * In Place:Yes
 * Adaptive:Yes
 * Stable:  Yes
 */

#ifndef __QUICK_H_
#define __QUICK_H_

#include <iostream>

#include "sort.h"

template <typename T>
class QuickSort : public Sort<T>
{
    private:
        int partition(std::vector<T>& v, int lo, int hi)
        {
            //if (lo >= hi)
            //    return;

            int i = lo;
            int j = hi + 1;

            while(true)
            {
                while(this->less(v[++i], v[lo])) 
                    if (i == hi) break;

                while(this->less(v[lo], v[--j]))
                    if (j == lo) break;

                if (i >= j) break;

                this->swap(v[i], v[j]);
            }

            this->swap(v[lo], v[j]);
            return j;
        }

        void sort(std::vector<T>& v, int lo, int hi)
        {
            if(hi <= lo) return;
            int j = partition(v, lo, hi);
            sort(v, lo, j-1);
            sort(v, j+1, hi);
        }

    public:
        virtual void sort(std::vector<T>& v)
        {
            std::cout << "Quick Sorting..." << std::endl;
            sort(v, 0, v.size() - 1);
        }
};

#endif
