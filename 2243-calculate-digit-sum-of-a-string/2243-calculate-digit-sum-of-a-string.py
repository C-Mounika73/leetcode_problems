class Solution:
    def digitSum(self, s: str, k: int) -> str:
        if s==0:
            return 0
        
        while len(s)>k:
            temp=""

            for i in range(0,len(s),k):
                grp=s[i:i+k]
                total=sum(int(j) for j in grp)
                temp+=str(total)
            s=temp
        
        return s

