#include <iostream>
#include <limits>
#include <algorithm>
#include <sstream>
using namespace std;


unsigned int GetOptimumAttempts(unsigned int no_of_floors, unsigned int number_of_eggs)
{
    if(number_of_eggs == 1) return no_of_floors;
    if(no_of_floors == 1) return no_of_floors;
   
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
    return min_num_attempts;
}

int main(int argc, char** argv)
{
    int num_of_attemps = GetOptimumAttempts(20,3);
    cout << "# of attempts for 20 floors and 3 eggs = " << num_of_attemps <<endl;
    return 0;
}