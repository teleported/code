#include <stdexcept>
#include <cstddef>
#include <iostream>

using namespace std;

template <typename T>
class Stack
{
    private:
        T*  buf;
        int size;
        int buf_size;
        int array_access;

        void resize(size_t newsize) {

            T* newbuf = new T[newsize];

            for(int i = 0; i < size; ++i) {
                newbuf[i] = buf[i];
                array_access++;
            }

            delete[] buf;
            buf = newbuf;
            //buf_size = newsize;
        }

    public:
        Stack(){
            buf = new int[1];
            size = 0;
            buf_size = 1;
            array_access = 0;
        }

        ~Stack() {
            delete[] buf;
            cout << "Array access = " << array_access << endl;
        }

        bool isEmpty() {
            return (size == 0);
        }

        void push(const T& item) {
            if(size == buf_size)
                resize(buf_size * 2);

            size++;
            buf[size-1]= item;
            array_access++;
        }

        T pop() {
            if(size > 0) {
                T item = buf[size-1];
                array_access++;
                size--;
                
                if(size < buf_size/4)
                    resize(buf_size/2);

                return item;
            }
            throw runtime_error("pop() invoked on empty stack");
        }
};


int main()
{
    Stack<int> s;
    for(int i = 0; i < 100; i++)
        s.push(i);
    for(int i = 0; i < 100; i++)
        cout << s.pop() << endl;


}
