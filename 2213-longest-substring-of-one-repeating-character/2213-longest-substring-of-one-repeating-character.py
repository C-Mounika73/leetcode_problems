from typing import List

class Node:
    def __init__(self,first,last,prefix,suffix,best,length):
        self.first=first
        self.last=last
        self.prefix=prefix
        self.suffix=suffix
        self.best=best
        self.length=length


class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: List[int]) -> List[int]:

        n=len(s)
        tree=[None]*(4*n)


        def merge(left,right):

            first=left.first
            last=right.last
            prefix=left.prefix
            suffix=right.suffix
            best=max(left.best,right.best)

            if left.last==right.first:
                crossing=left.suffix+right.prefix
                best=max(best,crossing)

                if left.prefix==left.length:
                    prefix=left.prefix+right.prefix
                if right.suffix==right.length:
                    suffix=left.suffix+right.suffix
            
            return Node(
                first,
                last,
                prefix,
                suffix,
                best,
                left.length+right.length
            )

        def build(left,right,index):

            if left==right:
                ch=s[left]
                tree[index]=Node(
                    ch,ch,
                    1,1,1,
                    1
                )
                return 
            mid=(left+right)//2

            build(left,mid,index*2)
            build(mid+1,right,index*2+1)

            tree[index]=merge(
                tree[index*2],
                tree[index*2+1]
            )

        def update(left,right,pos,ch,index):
            if left==right:
                tree[index]=Node(
                    ch,ch,1,1,1,1
                )
                return
            mid=(left+right)//2

            if pos<=mid:
                update(left,mid,pos,ch,index*2)
            else:
                update(mid+1,right,pos,ch,index*2+1)

            tree[index]=merge(
                tree[index*2],
                tree[index*2+1]
            )
        
        build(0,n-1,1)
        answer=[]
        for i in range(len(queryIndices)):
            index =queryIndices[i]
            ch=queryCharacters[i]
            update(0,n-1,index,ch,1)
            answer.append(tree[1].best)
        
        return answer

        