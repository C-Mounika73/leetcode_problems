/*
LeetCode 1 - Two Sum

Problem:
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up
to target.

Approach:
Brute Force
Check every pair of elements and return the indices
when their sum equals the target.

Time Complexity: O(n²)
Space Complexity: O(1)
*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int i, j;
    int *ans = (int *)malloc(2 * sizeof(int));

    for(i = 0; i < numsSize - 1; i++) {
        for(j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                ans[0] = i;
                ans[1] = j;
                *returnSize = 2;
                return ans;
            }
        }
    }

    return NULL;
}