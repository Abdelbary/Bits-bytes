// ConvertBases.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {

public:
    string changeBase(string numAsString, int b1, int b2) {

        if (b1 != 10)
            numAsString = convertToBase10(b1,numAsString);

        if (b2 == 10)
            return numAsString;

        return convertFromBase10(b2, numAsString);
    }
private:
    string convertToBase10(int b1, string s)
    {
        int resNum = 0;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] >= '0' &&  s[i] <= '9')
                resNum += ((int)((int)s[i] - (int)'0')) * pow(b1, i);

            else
                resNum += ((int)((int)s[i] - (int)'A' + 10)) * pow(b1, i);
        }
           

        return convertNumToString(resNum);
    }

    string convertNumToString(int num)
    {
        string res = "";

        while (num)
        {
            res.push_back((num % 10) + '0');
            num /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }

    string convertFromBase10(int b2, string s)
    {
        string res = "";

        int num = convertStringToNum(s);

        while (num)
        {
            int temp = num % b2;
            if(temp > 10)
                res.push_back(temp - 10 + 'A');
            else
                res.push_back(temp + '0');
            num /= b2;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    int convertStringToNum(string s)
    {
        int num = 0;

        for (int i = 0; i < s.size(); i++)
        {
            num *= 10;
            num += s[i] - '0';
        }

        return num;
    }
};
int main()
{
    string s;
    int b1, b2;
    Solution ss;

    cin >> s >> b1 >> b2;
    cout << ss.changeBase(s, b1, b2) << endl;
    getchar();
}
