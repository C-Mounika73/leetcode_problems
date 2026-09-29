class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l=0
        ch=set()
        m_len=0
        for i in range(len(s)):
            while s[i] in ch:
                ch.remove(s[l])
                l+=1
            ch.add(s[i])

            m_len=max(m_len,i-l+1)
        return m_len

        
        