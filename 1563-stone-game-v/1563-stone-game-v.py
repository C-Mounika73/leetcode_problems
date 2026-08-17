class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        from functools import cache

        n = len(stoneValue)
        prefix = [0] * (n + 1)

        for i in range(n):
            prefix[i + 1] = prefix[i] + stoneValue[i]

        @cache
        def dp(left, right):
            if left >= right:
                return 0

            ans = 0
            l = 0
            r = prefix[right + 1] - prefix[left]

            for i in range(left, right):
                l += stoneValue[i]
                r -= stoneValue[i]

                if l < r:
                    if ans >= 2 * l:
                        continue
                    ans = max(ans, l + dp(left, i))

                elif l > r:
                    if ans >= 2 * r:
                        break
                    ans = max(ans, r + dp(i + 1, right))

                else:
                    ans = max(
                        ans,
                        l + dp(left, i),
                        r + dp(i + 1, right)
                    )

            return ans

        return dp(0, n - 1)