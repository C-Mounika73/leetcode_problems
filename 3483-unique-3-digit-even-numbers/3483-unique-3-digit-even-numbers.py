class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        freq=[0]*10
        count=0

        for d in digits:
            freq[d]+=1

        for h in range(1,10):
            if freq[h] ==0:
                continue

            freq[h]-=1

            for t in range(10):
                if freq[t]==0:
                    continue

                freq[t]-=1

                for u in range(0,10,2):
                    if freq[u]>0:
                        count+=1

                freq[t]+=1
            freq[h]+=1

        return count


                            