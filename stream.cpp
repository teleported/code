#include <iostream>

using namespace std;

class Base
{
    protected:
        int m_i;

        virtual ostream& print(ostream& o) {
            return o << m_i;
        }

        virtual istream& read(istream& i) {
            return i >> m_i;
        }

    public:
        Base(int i) : m_i(i) {
        }

        friend ostream& operator<<(ostream& o, Base& b);
        friend istream& operator>>(istream& i, Base& b);
};

class Derived : public Base
{
    private:
        int m_j;

    protected:
        virtual ostream& print(ostream& o) {
            return o << Base::m_i << " " << m_j;
        }

        virtual istream& read(istream& i) {
            i >> Base::m_i >> m_j;
        }

    public:
        Derived(int j) : m_j(j), Base(j+1) {
        }

        friend ostream& operator<<(ostream& o, Base& b);
        friend istream& operator>>(istream& i, Base& b);
};

ostream& operator<<(ostream& o, Base& b)
{
    return b.print(o);
}

istream& operator>>(istream& i, Base& b)
{
    return b.read(i);
}

int main()
{
    Base* b = new Base(9);
    Derived* d = new Derived(100);

    cin >> *b;
    cin >> *d;

    cout << *b << endl;
    cout << *d << endl;

    delete b;
    delete d;
}

