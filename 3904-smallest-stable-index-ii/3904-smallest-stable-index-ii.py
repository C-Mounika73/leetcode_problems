class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n=len(nums)

        min_i=[0]*n
        min_i[n-1]=nums[n-1]

        for i in range(n-2,-1,-1):
            min_i[i]=min(nums[i],min_i[i+1])

        max_i=nums[0]

        for i in range(n):
            max_i=max(max_i,nums[i])

            if max_i-min_i[i]<=k:
                return i
        return -1
        