# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        prev=head
        curr=head.next

        index=1

        first_critical=-1
        last_critical=-1

        min_distance=float('inf')
        while curr.next:
            is_max=curr.val > prev.val and curr.val>curr.next.val
            is_min=curr.val<prev.val and curr.val<curr.next.val

            if is_max or is_min:
                if first_critical==-1:
                    first_critical=index
                else:
                    distance=index-last_critical
                    min_distance=min(min_distance,distance)
                
                last_critical=index
            prev=curr
            curr=curr.next
            index +=1
        if first_critical==-1 or first_critical==last_critical:
            return[-1,-1]
        
        max_distance=last_critical-first_critical

        return[min_distance,max_distance]