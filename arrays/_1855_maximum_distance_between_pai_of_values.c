/*
LeetCode 1855 - Maximum Distance Between a Pair of Values

Problem:
Given two non-increasing arrays nums1 and nums2, find the maximum distance (j - i)
such that i <= j and nums1[i] <= nums2[j]. Return 0 if no valid pair exists.

Approach:
Use a two-pointer technique. Start with pointers i and j at 0.
If nums1[i] <= nums2[j], the pair is valid, so update the maximum distance
and move j forward to try increasing the distance. Otherwise, move i forward
to find a smaller value in nums1 that may satisfy the condition. Since both
arrays are non-increasing, each pointer moves at most once through its array.

Pattern: Two Pointers

Time Complexity: O(n + m)
Space Complexity: O(1)

Where:
n = nums1Size
m = nums2Size
*/

int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0;
    int maxDist = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            if (j - i > maxDist) {
                maxDist = j - i;
            }
            j++;
        } else {
            i++;
        }
    }

    return maxDist;
}