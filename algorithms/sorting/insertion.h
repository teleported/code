/*
 * Best:    O(n)
 * Worst:   O(n^2)
 * Average: O(kn), where k is the max distance between an element and it's actual place
 *
 * Online:  Yes
 * In Place:Yes
 * Adaprive:Yes
 * Stable:  Yes
 */

#ifndef __INSERTION_H_
#define __INSERTION_H_

#include <iostream>

#include "sort.h"

template <typename T>
class InsertionSort : public Sort<T>
{
    public:
        virtual void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
        {
            std::cout << "Insertion Sorting..." << std::endl;
            if(start == end)
                return;

            typename std::vector<T>::iterator i = start + 1;
            while(i != end) {
                typename std::vector<T>::iterator j = i;
                while(j != start) {
                    if(this->less(*j, *(j-1)))
                        this->swap(*j, *(j-1));
                    else 
                        break;
                    j--;
                }
                i++;
            }
        }
};

#endif
