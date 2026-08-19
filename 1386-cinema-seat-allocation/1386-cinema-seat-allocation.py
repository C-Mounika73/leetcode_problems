class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        if not reservedSeats:
            return n*2

        reserved={}

        for row,seat in reservedSeats:
            if row not in reserved:
                reserved[row]=set()
            reserved[row].add(seat)

        empty_rows=n-len(reserved)
        total_groups=empty_rows*2

        for row,seats in reserved.items():
            count=0

            if not({2,3,4,5}&seats):
                count +=1

            if not({6,7,8,9}&seats):
                count +=1

            if count<2:
                if not({4,5,6,7}&seats):
                    count=max(count,1)

            total_groups +=count

        return total_groups