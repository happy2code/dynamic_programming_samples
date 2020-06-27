#include <iostream>
#include <map>
#include <sstream>

using namespace std;

map<unsigned int, unsigned long> counter;

unsigned long fibonacci(unsigned int number)
{
    if(number == 0){
        throw invalid_argument("number");
    }

    //cache[1] = 1;
    //cache[2] = 1;
    static map<unsigned int, unsigned long> cache = {
        {1,0},
        {2,1}
    };

    for(int i = 3; i <= number; i++)
    {
        cache[i] = cache[i-1] + cache[i-2];
    }

    return cache[number];
}

int main(int argc , char** args)
{
    if(argc < 2) {
        cout << "Pass atleast one argument, N";
        return -1;
    }

    stringstream ss;
    ss << args[1];

    unsigned long input_number;
    ss >> input_number;

    cout<< input_number << "th fobonacci number is " << fibonacci(input_number) <<endl;
    for(auto item : counter){
        cout << "Fibonacchi of " << item.first << " is called " << item.second << " times" << endl;
    }
}