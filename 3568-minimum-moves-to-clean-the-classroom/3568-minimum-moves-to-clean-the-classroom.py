class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:

        m=len(classroom)
        n=len(classroom[0])

        start=None
        litter={}
        litter_count=0

        for r in range(m):
            for c in range(n):
                if classroom[r][c]=='S':
                    start=(r,c)

                elif classroom[r][c]=='L':
                    litter[(r,c)]=litter_count
                    litter_count +=1
        all_mask=(1 << litter_count)-1

        q=deque()
        q.append((start[0],start[1],energy,0))

        visited=set()
        visited.add((start[0],start[1],energy,0))
        moves=0
        directions=[(-1,0),(1,0),(0,-1),(0,1)]

        while q:
            for _ in range(len(q)):
                r,c,current_energy,mask=q.popleft()

                if mask==all_mask:
                    return moves
                for dr,dc in directions:
                    nr=r+dr
                    nc=c+dc

                    if nr<0 or nr>=m or nc<0 or nc>=n:
                        continue
                    if classroom[nr][nc]=='X':
                        continue
                    if current_energy==0:
                        continue

                    new_energy=current_energy-1
                    new_mask=mask

                    if classroom[nr][nc]=='L':
                        index=litter[(nr,nc)]
                        new_mask=mask | (1 << index)

                    if classroom[nr][nc]=='R':
                        new_energy=energy
                    
                    new_state=(nr,nc,new_energy,new_mask)

                    if new_state not in visited:
                        visited.add(new_state)
                        q.append(new_state)


            moves +=1
        return -1

        