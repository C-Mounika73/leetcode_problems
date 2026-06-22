/*
LeetCode 2121 - Intervals Between Identical Elements

Problem:
Given an array nums, compute for each index i the sum of absolute differences
between i and every other index j where nums[i] == nums[j]. If no such index
exists, the result for that position is 0.

Approach:
Store each element along with its original index and sort by value. For each
group of equal values, build a prefix sum of their indices. Using prefix sums,
compute the contribution from indices on the left and right of each occurrence
in O(1), then place the result back at its original position.

Pattern: Prefix Sum

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

int cmp(const void* a, const void* b) {
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;
    if(p1->val == p2->val)
        return p1->idx - p2->idx;
    return p1->val - p2->val;
}

long long* distance(int* nums, int numsSize, int* returnSize) {
    
    Pair arr[numsSize];
    for(int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    qsort(arr, numsSize, sizeof(Pair), cmp);

    long long* result = (long long*)calloc(numsSize, sizeof(long long));

    int i = 0;
    while(i < numsSize) {
        int j = i;

        // group same values
        while(j < numsSize && arr[j].val == arr[i].val) {
            j++;
        }

        int size = j - i;

        // prefix sum of indices
        long long prefix[size];
        prefix[0] = arr[i].idx;

        for(int k = 1; k < size; k++) {
            prefix[k] = prefix[k-1] + arr[i+k].idx;
        }

        for(int k = 0; k < size; k++) {
            int index = arr[i+k].idx;

            long long left = (long long)arr[i+k].idx * k - (k > 0 ? prefix[k-1] : 0);
            long long right = (prefix[size-1] - prefix[k]) - (long long)arr[i+k].idx * (size-k-1);

            result[index] = left + right;
        }

        i = j;
    }

    *returnSize = numsSize;
    return result;
}