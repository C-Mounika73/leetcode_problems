class Solution:
    def checkDivisibility(self, n: int) -> bool:
        sum=0
        product=1
        temp=n

        while temp >0:
            digit=temp%10
            sum +=digit
            product *=digit
            temp //=10

        total=sum+product
        
        return n % total == 0
        