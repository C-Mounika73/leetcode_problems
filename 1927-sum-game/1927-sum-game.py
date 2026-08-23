class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        half = n // 2

        left_q = 0
        right_q = 0
        diff = 0

        for i in range(half):
            if num[i] == '?':
                left_q += 1
            else:
                diff += int(num[i])

        for i in range(half, n):
            if num[i] == '?':
                right_q += 1
            else:
                diff -= int(num[i])

        # Odd number of '?' -> Alice makes the last move
        if (left_q + right_q) % 2 == 1:
            return True

        # Bob can force equality only in this case
        return diff != 9 * (right_q - left_q) // 2