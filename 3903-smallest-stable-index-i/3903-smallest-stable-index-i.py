class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n=len(nums)

        suff_min=[0]*n
        suff_min[n-1]=nums[n-1]

        for i in range(n-2,-1,-1):
            suff_min[i]=min(nums[i],suff_min[i+1])
        max_so_far=nums[0]

        for i in range(n):
            max_so_far=max(max_so_far,nums[i])

            if max_so_far - suff_min[i]<=k:
                return i
        
        return -1
        