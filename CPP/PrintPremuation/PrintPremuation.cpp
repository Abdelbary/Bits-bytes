// PrintPremuation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int n = 4;


void printPremutation(vector<int>& p, int i)
{
    if (i == p.size())
    {
        for (auto x : p)
            cout << x << " ";
        cout << endl;
        return;
    }
    
    for (int j = i+1; j < p.size(); j++)
    {   
        swap(p[i],p[j]);

        printPremutation(p, i + 1);

        swap(p[i], p[j]);
    }
        
}
int main()
{

    vector<int> v = { 1,2,3,4 };
    printPremutation(v, 0);
}
