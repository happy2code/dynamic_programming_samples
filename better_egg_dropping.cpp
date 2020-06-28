#include <iostream>
#include <limits>
#include <algorithm>
#include <map>
using namespace std;

map<unsigned int, map<unsigned int,unsigned int>> cache;

unsigned int GetOptimumAttempts(unsigned int no_of_floors, unsigned int number_of_eggs)
{
    if(number_of_eggs == 1) return no_of_floors;
    if(no_of_floors == 1) return no_of_floors;
    if(cache[no_of_floors][number_of_eggs] != 0)
    {
        return cache[no_of_floors][number_of_eggs];
    }

    auto min_num_attempts = numeric_limits<unsigned int>::max();
    for(auto currentfloor = 1; currentfloor < no_of_floors; currentfloor++) {
        //if egg breaks, you have one egg less and you need to search in the floors less than the floor number
        int result1 = 1 + GetOptimumAttempts(currentfloor-1,number_of_eggs-1);

        //if egg does not break, you have same number of eggs and you have to search in all the floors above
        int result2 = 1 + GetOptimumAttempts(no_of_floors - currentfloor,number_of_eggs);

        auto attempts = max(result1,result2);
        if( attempts < min_num_attempts)
        {
            min_num_attempts = attempts;
        }
            
    }
    cache[no_of_floors][number_of_eggs] = min_num_attempts; 
    return min_num_attempts;
}

int main()
{
    cout << " The attempts =" << GetOptimumAttempts(100,2) << endl;
}