#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream f("data/random.txt", std::ifstream::in);
    std::string line;
    vector<string> v;

    while(std::getline(f, line))
        v.push_back(line);

    cout << v.size() << endl;
    f.close();

}
