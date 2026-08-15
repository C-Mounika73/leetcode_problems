class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        n=len(nums)
        has_non_zero=any(num!=0 for num in nums)

        if not has_non_zero:
            return 0
        
        xor=0
        for num in nums:
            xor=xor^num

        if xor!=0:
            return n
        
        return n-1