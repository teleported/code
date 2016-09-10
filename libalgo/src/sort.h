#ifndef __SORT_H_
#define __SORT_H_

#include <vector>
#include <string>

using namespace std; // Should not to in header

template <typename T>
class Sort
{
    public:
        virtual void sort(vector<T>& list) = 0; 
        virtual ~Sort() {}
    protected:
        virtual bool less(const T& left, const T& right) {
            return left < right;
        }

        virtual void swap(T& left, T& right) {
            T temp = left;
            left = right;
            right = temp;
        }
};


template <typename T>
class Selection: public Sort<T>
{
    public:
        virtual void sort(vector<T>& list) {

            size_t size = list.size();

            for(int i = 1; i < size; ++i)
                for(int j = i; j > 0; --j)
                    if(this->less(list[j], list[j-1])) {
                        this->swap(list[j], list[j-1]);
                    }
        }
};

#endif // __SORT_H_
