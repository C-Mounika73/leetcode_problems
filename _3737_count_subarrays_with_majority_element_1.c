/*
LeetCode 3764 - Count the Number of Majority Element Subarrays

Problem:
Given an integer array and a target value, count the number of subarrays
where the target appears strictly more than half of the subarray length.

Approach:
Convert the array into +1 (if element equals target) and -1 (otherwise).
Build a prefix sum array over these values. For any subarray, the target is
the majority iff its transformed sum is positive, which is equivalent to
prefix[right + 1] > prefix[left]. Check all pairs of prefix sums using two
nested loops and count the valid ones.

Pattern: Prefix Sum

Time Complexity: O(n²)
Space Complexity: O(n)
*/


int countMajoritySubarrays(int* nums, int numsSize, int target) {
    int prefix[1001];
    prefix[0] = 0;

    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target)
            prefix[i + 1] = prefix[i] + 1;
        else
            prefix[i + 1] = prefix[i] - 1;
    }

    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j <= numsSize; j++) {
            if (prefix[j] > prefix[i])
                ans++;
        }
    }

    return ans;
}