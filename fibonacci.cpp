#include <iostream>
#include <map>
#include <sstream>

using namespace std;

map<unsigned int, unsigned int> counter;
unsigned long fibonacci(unsigned int number)
{
    if(number <= 0){
        throw invalid_argument("number");
    }
    
    if(number == 1) return 0;
    if(number == 2) return 1;

    ++counter[number];
    return fibonacci(number-1) + fibonacci(number-2);
}

//0 1 1 2 3 5 8 13 21 34 55 ...
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