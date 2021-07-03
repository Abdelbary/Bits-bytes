// Program to print all permutations of a string in sorted order.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int cielIndx(std::string s, int v, int i)
{
    int ind = i;

    for (int j = i + 1; j < s.size(); j++)
        if (s[j] > v && s[j] < s[ind])
            ind = j;

    return ind;
}
void sortedPermutations(std::string s)
{
    int len = s.size();

    std::sort(s.begin(), s.end());

    bool finished = false;

    while (!finished)
    {
        printf("%s\n", s.c_str());

        int i;
        for (i = len - 2; i >= 0; i--)
            if (s[i] < s[i + 1])
                break;
        
        if (i == -1)
            break;
        else 
        {
            int cielInd = cielIndx(s, s[i], i + 1);

            std::swap(s[i], s[cielInd]);

            std::sort(s.begin() + i + 1, s.end());
        }
        
    }
}

// Driver program to test above function
int main()
{
    std::string str = "1234";
    sortedPermutations(str);
    return 0;
}