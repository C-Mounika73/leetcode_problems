class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        mod = 10**9 + 7

        dp = [[0] * (k + 1) for _ in range(n + 1)]

        for i in range(n + 1):
            dp[i][0] = 1

        for j in range(1, k + 1):
            prefix = 0

            for i in range(1, n + 1):

                # Don't use i-1 as the endpoint
                dp[i][j] = dp[i - 1][j]

                # Running sum of dp[p+1][j-1]
                if i >= 2:
                    prefix = (prefix + dp[i - 1][j - 1]) % mod

                # Use i-1 as the endpoint
                dp[i][j] = (dp[i][j] + prefix) % mod

        return dp[n][k]