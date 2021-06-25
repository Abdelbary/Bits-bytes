#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int convertString(string  s)
    {
        int x = (s[0] * 10 + s[1]) * 60;
        x += s[3] * 10 + s[4];

        return x;
    }
    int timeDifference(vector<string>& times) {

        vector<int> timeInMin;

        for (auto e : times)
        {
            timeInMin.push_back(convertString(e));
        }

        sort(timeInMin.begin(), timeInMin.end());

        int Min = INT_MAX;
        for (int i = 0; i < timeInMin.size() - 1; i++)
            Min = min(Min, timeInMin[i + 1] - timeInMin[i]);

        Min = min(Min, 1440 - timeInMin[timeInMin.size() - 1] + timeInMin[0]);
        return Min;
    }
};


int main()
{
    vector<string> ss = { "00:03", "23:59", "12:03" };

    Solution sol;

    cout<< sol.timeDifference(ss)<<endl;
    getchar();
    return 0;
}