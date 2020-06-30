#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int GetMinCoins(const vector<int>& coins, int amount)
{

    if(amount < 0)
    {
        return numeric_limits<int>::max(); 
    }

    if(amount == 0){
        return 0;
    }

    auto no_of_coins = numeric_limits<int>::max(); 

    for(auto coin : coins){
            int result = GetMinCoins(coins,amount-coin);
            if(result != numeric_limits<int>::max())
                no_of_coins = min(no_of_coins,result + 1);
    }
    return no_of_coins;
}

int main()
{
    vector<int> coins = {1,2,3,4,5};
    int amount = 11;
    cout << GetMinCoins(coins,amount);
}