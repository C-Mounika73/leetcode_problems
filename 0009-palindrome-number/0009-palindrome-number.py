class Solution:
    def isPalindrome(self, x: int) -> bool:
        temp=x
        sum=0
        if x<0:
            return False
        while x!=0:
            digit=x%10
            sum=sum*10+digit
            x=x//10
        return temp==sum