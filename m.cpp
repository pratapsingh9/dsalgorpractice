#include <bits/stdc++.h>
using namespace std;

int maximiseMemeory(vector<int> memory)
{
    sort(memory.rbegin(), memory.rend());
    int total = 0;
    for (int i = 0; i < memory.size(); i++)
    {
        total += (i + 1) * (int)memory[i];
    }
    return total;
}

int main()
{
    vector<int> meoory = {3, 4, 5};
    cout << maximiseMemeory(meoory) << endl;
    return 0;
}

int smallestPostiiveNumber(vector<int> nums)
{
    sort(nums.begin(), nums.end());
}

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r)
        {
            /* code */
            int mid = l + (r - l) / 2;

            bool evenCheck = (mid % 2) == 0;
            if (evenCheck)
            {
                /* code */
                if (nums[mid] == nums[mid + 1])
                {
                    /* code */
                    l = mid + 2;
                }
                else
                {
                    r = mid;
                }
            }
            else
            {
                if (nums[mid] == nums[mid + 1])
                {
                    /* code */
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        return nums[l];
    }
};
