#include <iostream>
#include <vector>
#include <string>

using namespace std;

class StrList
{
    mutable vector<string> m_v;

    public:
    const string& operator[](size_t index) const {
        return m_v[index];
    }

    string& operator[](size_t index) {
        return m_v[index];
    }

    void add(const string& item) const {
        m_v.push_back(item);
    }
};

int main()
{
    const StrList s;
    s.add("Anand");
    s.add("Trisha");
    s.add("Deepa");

    cout << s[0] << endl;
    cout << s[1] << endl;
    cout << s[2] << endl;

    cout << "--" << endl;
    s[0] = "Anand Saha";
    s[1] = "Trisha Saha";
    s[2] = "Deepa Saha";

    cout << s[0] << endl;
    cout << s[1] << endl;
    cout << s[2] << endl;



}
