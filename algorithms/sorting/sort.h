#ifndef __SORT_H_
#define __SORT_H_

#include <vector>
#include <string>
#include <iostream>

template <typename T>
class Sort
{
    public:
        virtual void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
        {
            throw "Not implemented";
        }
        virtual void sort(std::vector<T>& v)
        {
            throw "Not implemented";
        }

        virtual ~Sort() {}

        virtual bool less(const T& left, const T& right) {
            return left < right;
        }

        virtual void swap(T& left, T& right) {
            T temp = left;
            left = right;
            right = temp;
        }

        virtual bool validate(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
            while(start != (end-1)) {
                if(*start > *(start+1))
                    return false;
                start++;
            }
            return true;
        }

        virtual void print(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
            while(start != end) {
                std::cout << *start << std::endl;
                start++;
            }
        }


};
#endif
