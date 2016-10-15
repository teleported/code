/*
 * Best:    
 * Worst:   
 * Average: 
 *
 * Takes at most NlogN compares and 6NlogN array acesses
 * Online:  No
 * In Place:No
 * Adaptive:Yes
 * Stable:  Yes
 */

#ifndef __MERGE_H_
#define __MERGE_H_

#include <iostream>

#include "sort.h"

template <typename T>
class MergeSort : public Sort<T>
{
    private:
        void merge(std::vector<T>& v, std::vector<T>& a, int lo, int mid, int hi)
        {
            for(int k = lo; k <= hi; ++k)
                a[k] = v[k];

            int i = lo;
            int j = mid + 1;
            for(int k = lo; k <= hi; ++k)
            {
                if(i > mid)                         v[k] = a[j++];
                else if (j > hi)                    v[k] = a[i++];
                else if (this->less(a[i], a[j]))    v[k] = a[i++];
                else                                v[k] = a[j++];
            }
        }

        void sort(std::vector<T>& v, std::vector<T>& a, int lo, int hi)
        {
            if(hi <= lo)
                return;
            int mid = lo + (hi-lo)/2;
            sort(v, a, lo, mid);
            sort(v, a, mid+1,hi);
            merge(v, a, lo, mid, hi);
        }

    public:
        virtual void sort(std::vector<T>& v)
        {
            std::cout << "Merge Sorting..." << std::endl;
            std::vector<T> a = v;
            sort(v, a, 0, v.size() - 1);
        }
};

#endif
