// The 3-sum Problem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        sort(A.begin(), A.end());
        vector<vector<int>> res;
        set<vector<int>> s;
        for (int i = 0; i < A.size() - 1; i++)
            for (int j = i + 1; j < A.size(); j++)
            {
                int sum = A[i] + A[j];


                if (binary_search(A.begin() + j + 1, A.end(), (-1 * sum)))
                {
                    if (!s.count({ A[i],A[j],(-1 * sum) }))
                    {
                        res.push_back({ A[i],A[j],(-1 * sum) });
                        s.insert({ A[i],A[j],-1 * sum });
                    }

                }
            }

        return res;
    }

    vector<vector<int>> threeSum2(vector<int>& A) {
        sort(A.begin(), A.end());
        vector<vector<int>> res;
        set<vector<int>> s;
        for (int i = 0; i < A.size() - 1; i++)
        {
            int en = A.size() - 1, st = i + 1;

            while (st < en)
            {
                if (A[i] + A[st] + A[en] == 0 && !s.count({ A[i] , A[st] , A[en] }))
                {
                    res.push_back({ A[i] , A[st] , A[en] });
                    s.insert({ A[i] , A[st] , A[en] });
                }
                else if (A[i] + A[st] + A[en] > 0)
                    en--;
                else
                    st++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v{ -3,2,-1,0,1,-2 };
    vector<vector<int>> triples = s.threeSum2(v);

    for (auto vec : triples)
    {
        for (auto e : vec)
            cout << e << " ";

        cout << endl;
    }
       
    getchar();
}
