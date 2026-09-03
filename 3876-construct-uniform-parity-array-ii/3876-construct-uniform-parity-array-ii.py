class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        mn=min(nums1) #we cannot change the min element as odd or even , so we follow the same pattern as smallest element.if smallest is odd every element should be odd , if it is even then every element is even

        if mn%2 ==1:
            return True # if smallest is odd we can make every element odd by subtracting it with the smalles one
        
        for x in nums1:
            if x%2==1:
                return False #if there is an odd element in nums1 with even element as nums2 we cannot make everything as even because atleast one element remains odd
        
        return True
        