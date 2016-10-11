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

#ifndef __SHELL_H_
#define __SHELL_H_

#include <iostream>
#include <iterator>
#include "sort.h"

template <typename T>
class ShellSort : public Sort<T>
{
    public:
        virtual void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
        {
            std::cout << "Shell Sorting..." << std::endl;

            if(start == end)
                return;

            unsigned int size = std::distance(start, end);
            unsigned int h = 1;

            while(h < size/3) {
                h = 3*h + 1;
            }

            while(h >= 1) {
                typename std::vector<T>::iterator i = start + h;
                while(i != end) {
                    typename std::vector<T>::iterator j = i;
                    while(std::distance(start, j) >= h) {
                        if(this->less(*j, *(j-h)))
                            this->swap(*j, *(j-h));
                        else 
                            break;
                        j = j - h;
                    }
                    i++;
                }
                h = h/3;
            }
        }
};

#endif
