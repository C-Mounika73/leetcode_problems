class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0

        prime = [True] * n
        prime[0] = prime[1] = False

        for i in range(2, int(n ** 0.5) + 1):
            if prime[i]:
                prime[i * i:n:i] = [False] * (((n - 1 - i * i) // i) + 1)

        return sum(prime)