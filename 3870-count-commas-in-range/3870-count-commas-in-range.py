class Solution:
    def countCommas(self, n: int) -> int:
        count=0
        if n<=999 :
            return 0
        else:
            count=n-999
        
        return count

        