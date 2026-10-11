class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        sum=0
        n=len(nums)
        i=0

        while i<n:
            if n%(i+1)==0:
                sum+=nums[i]*nums[i]
            i+=1

        return sum            

