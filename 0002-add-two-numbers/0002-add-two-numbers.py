
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        temp=ListNode(0)
        cur=temp
        carry=0
        while l1 or l2:
            a=l1.val if l1 else 0
            b=l2.val if l2 else 0
            s=a+b+carry
            carry=s//10
            cur.next=ListNode(s%10)
            cur=cur.next
            if l1:
                l1=l1.next
            if l2:
                l2=l2.next
        if carry:
            cur.next=ListNode(carry)
        return temp.next
        
        
        