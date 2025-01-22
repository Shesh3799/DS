#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int findTargetSumWaysMemo(vector<int> &nums, int target, int curr_sum, int n)
{
    if (n == 0)
        return 0;

    if (target == curr_sum)
        cnt++;

    // Add + to num
    int withPositive = findTargetSumWaysMemo(nums, target, curr_sum + nums[n - 1], n - 1);

    // Add - to num
    int withNegative = findTargetSumWaysMemo(nums, target, curr_sum - nums[n - 1], n - 1);

    return withPositive + withNegative;
}
int findTargetSumWays(vector<int> &nums, int target)
{
    return findTargetSumWaysMemo(nums, target, 0, nums.size());
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << findTargetSumWays(nums, target) << endl;

    return 0;
}