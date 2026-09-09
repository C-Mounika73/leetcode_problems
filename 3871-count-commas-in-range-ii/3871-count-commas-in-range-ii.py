class Solution:
    def countCommas(self, n: int) -> int:
        count = 0
        start = 1000
        commas = 1

        while start <= n:
            end = start * 1000 - 1
            actual_end = min(n, end)

            numbers = actual_end - start + 1
            count += numbers * commas

            start *= 1000
            commas += 1

        return count