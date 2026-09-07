class Solution:
    def distinctSubseqII(self, s: str) -> int:
        mod=10**9+7

        dp=1 #at first for every s there is one subsequence that is " "
        last=[0]*26 #we have 26 alphabets in english , intialize every alphabet index to 0

        for ch in s:
            i=ord(ch)-ord('a') #converting the ascii value to index
            new_dp=(2*dp-last[i])%mod 
            last[i]=dp #updating the last with dp to remove duplicates
            dp=new_dp
        return (dp-1)%mod