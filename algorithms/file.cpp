#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream f("pg27780.txt", std::ifstream::in);
    std::string line;

    while(std::getline(f, line))
        cout << line << endl;

    f.close();
}
