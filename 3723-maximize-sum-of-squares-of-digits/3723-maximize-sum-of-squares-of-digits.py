'''class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        arr=[]
    
        for i in range (10**(num-1),10**num):
            sum1=0
            temp=i
            while temp>0:
                digit=temp%10
                sum1+=digit
                temp//=10

            if sum1==sum:
                arr.append(i)
        
        if not arr:
            return ""

        max=0
        for j in arr:
            sum2=0
            temp1=j
            while temp1>0:
                digit_=temp1%10
                sum2+=digit_**2
                temp1//=10

            if sum2>max:
                max=sum2

        return str(j)
'''
class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > 9 * num:
            return ""


        ans = []

        for i in range(num):
            digit = min(9, sum)
            ans.append(str(digit))
            sum -= digit

        return "".join(ans)

