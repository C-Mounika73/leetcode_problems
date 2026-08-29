class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        
        arr=sorted((value,index) for index,value in enumerate(nums))

        res=nums[:]

        n=len(nums)
        i=0

        while i<n:
            grp_val=[]
            grp_ind=[]

            grp_val.append(arr[i][0])
            grp_ind.append(arr[i][1])

            j=i+1

            while j<n and arr[j][0]-arr[j-1][0]<=limit:
                grp_val.append(arr[j][0])
                grp_ind.append(arr[j][1])

                j+=1

            grp_val.sort()
            grp_ind.sort()

            for k in range(len(grp_val)):
                res[grp_ind[k]]=grp_val[k]

            i=j

        return res
