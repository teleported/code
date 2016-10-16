#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "sort.h"
#include "insertion.h"
#include "selection.h"
#include "shell.h"
#include "merge.h"
#include "utility.h"
#include "quick.h"

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
/*
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
*/
int main()
{
    vector<string> v;
    populate_words(v, false);
    //populate_lite(v);

    cout << "Starting ..." << endl;

    clock_t begin_time;
    clock_t end_time;
/*
    SelectionSort<string> se;
    begin_time = clock();
    se.sort(v.begin(), v.end());
    end_time = clock();
    cout << "Sorted? " << std::boolalpha << se.validate(v.begin(), v.end()) << endl;
    cout << "Time taken (ms): " << diffclock_ms(begin_time, end_time) << endl;

    ShellSort<string> s;
    begin_time = clock();
    s.sort(v.begin(), v.end());
    end_time = clock();
    cout << "Sorted? " << std::boolalpha << s.validate(v.begin(), v.end()) << endl;
    cout << "Time taken (ms): " << diffclock_ms(begin_time, end_time) << endl;

    MergeSort<string> m;
    begin_time = clock();
    m.sort(v);
    end_time = clock();
    cout << "Sorted? " << std::boolalpha << m.validate(v.begin(), v.end()) << endl;
    cout << "Time taken (ms): " << diffclock_ms(begin_time, end_time) << endl;
    //i.print(v.begin(), v.end());
*/
    QuickSort<string> q;
    begin_time = clock();
    q.sort(v);
    end_time = clock();
    cout << "Sorted? " << std::boolalpha << q.validate(v.begin(), v.end()) << endl;
    cout << "Time taken (ms): " << diffclock_ms(begin_time, end_time) << endl;


}
