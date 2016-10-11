#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "sort.h"
#include "insertion.h"
#include "selection.h"
#include "shell.h"

using namespace std;

void populate_lite(vector<string>& v) 
{
    v.push_back("Pune");
    v.push_back("Kolkata");
    v.push_back("Chennai");
    v.push_back("Vadodara");
    v.push_back("Haldia");
    v.push_back("Trichy");
    v.push_back("Delhi");
}

void populate_words(vector<string>& v, bool load_lite = true) 
{
    string filename = "../data/random_lite.txt";

    if(!load_lite)
        filename = "../data/random.txt"; 

    ifstream f(filename, std::ifstream::in);
    std::string line;

    while(std::getline(f, line))
        v.push_back(line);

    cout << v.size() << " words populated" << endl;
    f.close();
}

bool validate(vector<string>::iterator start, vector<string>::iterator end) {
    while(start != (end-1)) {
        string a = *start;
        string b = *(start+1);
        if(a > b)
            return false;
        start++;
    }
    return true;
}

int main()
{
    vector<string> v;
    populate_words(v, false);
    //populate_lite(v);

    ShellSort<string> i;
    i.sort(v.begin(), v.end());
    cout << "Sorted? " << std::boolalpha << i.validate(v.begin(), v.end()) << endl;
    //i.print(v.begin(), v.end());

}
