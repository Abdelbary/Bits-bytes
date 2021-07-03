// nextPermutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {

        int len = nums.size();

        int i;
        
        for (i = len - 2; i >= 0; i--)
            if (nums[i] < nums[i + 1]) break;

        int swapInd = i + 1;

        for (int j = swapInd; j < len; j++)
            if (nums[j] > nums[i] && nums[j] < nums[swapInd])
                swapInd = j;

        swap(nums[i], nums[swapInd]);

        sort(nums.begin() + i + 1, nums.end());

        return nums;
    }
};


int main()
{
    std::cout << "Hello World!\n";

}
