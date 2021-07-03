// Prime_Seive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<algorithm>
#include<vector>
int nPrime[10000];

class Solution {
public:;

    vector<int> enumratePrimes(int n)
    {
        vector<int> res;

        nPrime[1] = 1;
        for (int i = 2; i < n; i++)
            if (!nPrime[1])
            {
                for (int j = i; j <= n; j += i)
                {
                    nPrime[j] = 1;
                    std::cout << j << " " << std::endl;
                }
            }




        for (int i = 1; i <= n; i++)
            if (!nPrime[i])
                res.push_back(i);

        return res;
    }
};

int main()
{
    
    //Solution s;
    //vector<int> x = s.enumeratePrimes(7);

}

