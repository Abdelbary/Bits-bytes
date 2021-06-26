// sortArray123.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray_0_1_2(vector<int>& nums) {

        int st = 0, en = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++)
            while ((nums[i] == 0 || nums[i] == 2) && i >= st && i <= en)
                if (nums[i] == 0)
                {
                    int tmp = nums[i];
                    nums[i] = nums[st];
                    nums[st] = tmp;
                    st++;
                }
                else if (nums[i] == 2)
                {
                    int tmp = nums[i];
                    nums[i] = nums[en];
                    nums[en] = tmp;
                    en--;
                }

        return nums;

    }
};
int main()
{
    vector<int> v;
    int x;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        v.push_back(x);
    }

    Solution s;
    s.sortArray_0_1_2(v);


    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    
}

