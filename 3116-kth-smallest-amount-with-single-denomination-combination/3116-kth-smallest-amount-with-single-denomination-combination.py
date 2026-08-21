from math import gcd

class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:

        def count(x):
            total = 0
            n = len(coins)

            # Check every combination of coins
            for mask in range(1, 1 << n):
                lcm = 1
                bits = 0

                for i in range(n):
                    if mask & (1 << i):
                        bits += 1

                        g = gcd(lcm, coins[i])
                        lcm = lcm // g * coins[i]

                        if lcm > x:
                            break

                else:
                    # Inclusion-Exclusion
                    if bits % 2 == 1:
                        total += x // lcm
                    else:
                        total -= x // lcm

            return total

        # Binary Search
        left = 1
        right = min(coins) * k

        while left < right:
            mid = (left + right) // 2

            if count(mid) >= k:
                right = mid
            else:
                left = mid + 1

        return left