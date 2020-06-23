#include <iostream>
#include <map>

using namespace std;

map<unsigned int, unsigned long> counter;

unsigned long fibonacci(unsigned int number)
{
    static map<unsigned int, unsigned long> cache = {
        {0,1},
        {1,1}
    };

    ++counter[number];
    if(cache.find(number) == end(cache))
    {
        cache[number] = fibonacci(number-1) + fibonacci(number-2);
    }

    return cache[number];
}

int main()
{
    cout<< "25th fobonacci number is " << fibonacci(25) <<endl;
    for(auto item : counter){
        cout << "Fibonacci of " << item.first << " is called " << item.second << " times" << endl;
    }

    return 0;
}