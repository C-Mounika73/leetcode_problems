/*
LeetCode 4 - Median of Two Sorted Arrays

Problem:
Given two sorted arrays nums1 and nums2 of sizes m and n,
return the median of the two sorted arrays.

Approach:
Merge the two sorted arrays into a single sorted array.
Then find the median based on whether the total number
of elements is odd or even.

Time Complexity: O(m + n)
Space Complexity: O(m + n)

Note:
The problem asks for an O(log(m+n)) solution, but this
implementation uses the simpler merge approach.
*/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int result[nums1Size + nums2Size];
    int i=0,j=0,k=0;
    while(i<nums1Size && j<nums2Size){
        if(nums1[i]<=nums2[j]){
            result[k++]=nums1[i];
            i++;
        }else{
            result[k++]=nums2[j];
            j++;
        }
    }

    while(i<nums1Size){
        result[k++]=nums1[i++];
    }

    while(j<nums2Size){
        result[k++]=nums2[j++];
    }

    if((nums1Size + nums2Size)%2==1){
    return result[(nums1Size+nums2Size)/2];
    }else{
        return (result[(nums1Size+nums2Size)/2-1] + result[(nums1Size+nums2Size)/2])/2.0;
    }
}