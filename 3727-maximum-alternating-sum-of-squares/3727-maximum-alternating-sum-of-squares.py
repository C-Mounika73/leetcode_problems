class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        nums=sorted(x*x for x in nums)

        n=len(nums)
        mid=n//2

        return sum(nums[mid:])-sum(nums[:mid])