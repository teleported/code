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

        void resize(size_t newsize) {
            cout << "Resizing to " << newsize << endl;

            T* newbuf = new T[newsize];

            for(int i = 0; i < size; ++i)
                newbuf[i] = buf[i];

            delete[] buf;
            buf = newbuf;
            buf_size = newsize;
        }

    public:
        Stack(){
            buf = new int[1];
            size = 0;
            buf_size = 1;
        }

        ~Stack() {
            delete[] buf;
        }

        bool isEmpty() {
            return (size == 0);
        }

        void push(const T& item) {
            if(size == buf_size)
                resize(buf_size * 2);

            size++;
            buf[size-1]= item;
        }

        T pop() {
            if(size > 0) {
                T item = buf[size-1];
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
