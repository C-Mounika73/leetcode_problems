class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        char_count=[0]*26
        left=0
        max_length=0

        for right in range(len(s)):
            char_index=ord(s[right])-ord('a')
            char_count[char_index]+=1

            while char_count[char_index]>2:
                left_char_index=ord(s[left])-ord('a')
                char_count[left_char_index] -=1
                left+=1

            max_length=max(max_length,right-left+1)

        return max_length