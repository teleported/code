#include <stdexcept>
#include <cstddef>
#include <iostream>

using namespace std;

template <typename T>
class Item
{
    public:
        T item;
        Item* next;

        Item(const T& i, Item* n) : next(n), item(i) {
        }
};

template <typename T>
class Stack
{
    public:
        Stack() : top(NULL) {
        }

        bool isEmpty() {
            return (top == NULL);
        }

        void push(const T& item) {
            Item<T>* i = new Item<T>(item, top);
            top = i; 
        }

        T pop() {
            if (top != NULL) {
                T item = top->item;
                Item<T>* del = top;
                top = del->next;
                delete del;
                return item;
            }
            throw std::runtime_error("pop() called on empty stack");
        }

    private:
        Item<T>* top;
};


int main()
{
    Stack<int> s;
    s.push(1);
    s.push(3);
    s.push(7);
    s.push(9);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    s.push(42);
    cout << s.pop() << endl;
}
