/*
 * Best:    O(n^2)
 * Worst:   O(n^2)
 * Average: O(n^2)
 *
 * Online:  No
 * In Place:Yes
 * Adaptive:No
 * Stable:  No
 */


#ifndef __SELECTION_H_
#define __SELECTION_H_

#include <iostream>
#include "sort.h"

template <typename T>
class SelectionSort : public Sort<T>
{
    public:
        virtual void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
        {
            std::cout << "Selection Sorting..." << std::endl;
            if(start == end)
                return;

            typename std::vector<T>::iterator i = start;
            while(i != (end-1)) {
                typename std::vector<T>::iterator j = i + 1;
                typename std::vector<T>::iterator min = i;
                while(j != end) {
                    if(this->less(*j, *min))
                        min = j;
                    j++;
                }
                this->swap(*i, *min);
                i++;
            }
        }
};

#endif
