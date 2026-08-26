class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:

        p=[]
        for i in range(len(s)):
            if s[i]=='1':
                p.append(i)

        if len(p)<k:
            return ""
        
        min_len=float('inf')
        ans=""

        for i in range(len(p)-k+1):
            left=p[i]
            right=p[i+k-1]
            length=right-left+1
            x=s[left:right+1]

            if length<min_len:
                min_len=length
                ans=x
            elif length==min_len and x<ans:
                ans=x

        return ans