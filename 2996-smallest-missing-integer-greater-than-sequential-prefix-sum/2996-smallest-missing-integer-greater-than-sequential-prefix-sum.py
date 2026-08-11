class Solution(object):
    def missingInteger(self, nums):
        i=0
        while i<len(nums)-1 and nums[i+1]==nums[i]+1:
            i+=1
        sum1=sum(nums[:i+1])
        num_set=set(nums)

        x=sum1
        while x in num_set:
            x+=1
        return x