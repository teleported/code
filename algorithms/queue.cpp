#include <iostream>
#include <stdexcept>

using namespace std;

#define nullptr 0

template <typename T>
class Item
{
    public:
        Item* next;
        T item;

        Item(const T& i, Item* n) : next(n), item(i) {
        }
};

template <typename T>
class Queue
{
    private:
        Item<T>* front;
        Item<T>* back;
        int size;

    public:
        Queue() : front(nullptr), back(nullptr), size(0) {
        }

        void enqueue(const T& item) {
            Item<T>* i = new Item<T>(item, size == 0? nullptr: back);
            back = i;
            if(size == 0)
                front = i;
            size++;
        }
        
        T dequeue() {
            if(size > 0) {
                T item = front->item;

                if(front == back) {
                    delete front;
                    front = back = nullptr;
                } else {
                    Item<T>* it = back;
                    while(1) {
                        if (it->next == front)
                            break;
                        it = it->next;
                    }
                    delete front;
                    front = it;
                }
                size--;
                return item;
            }
            throw runtime_error("dequeue() called on empty queue");
        }

        void print() {
            Item<T>* it = back;
            while(1) {
                cout << it->item << endl;
                if (it->next == nullptr)
                    break;
                it = it->next;
            }
        }
};

int main()
{
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.enqueue(42);
    cout << q.dequeue() << endl;
}
