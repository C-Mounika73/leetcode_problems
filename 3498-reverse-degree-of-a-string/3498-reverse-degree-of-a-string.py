class Solution:
    def reverseDegree(self, s: str) -> int:
        t=0
        for i in range(len(s)):
            r_v=26-(ord(s[i])-ord('a'))
            t+=r_v*(i+1)
        
        return t
        