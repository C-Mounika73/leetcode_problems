class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        count={}
        
        for i in range(len(nums)-k+1):
            subarray=set(nums[i:i+k])

            for j in subarray:
                count[j]=count.get(j,0) +1

        ans=-1

        for i in count:
            if count[i]==1:
                ans=max(ans,i)

        return ans

        
        