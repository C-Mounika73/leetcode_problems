class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n=len(nums)
        i=0
        j=0

        for k in range(n):
            if nums[i]>nums[k]:
                i=k
            if nums[j]<nums[k]:
                j=k
        left=min(i,j)
        right=max(i,j)

        front=right+1
        back=n-left
        both=(left+1)+(n-right)

        return min(front,back,both)
                               
        