class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        freq = [0] * 26

        for ch in s:
            freq[ord(ch) - ord('a')] += 1

        ans = []

        for i in range(len(target)):
            j = ord(target[i]) - ord('a')

            if freq[j] == 0:
                break

            freq[j] -= 1
            ans.append(target[i])

        else:
            i = len(target) - 1

        if len(ans) < len(target):
            j = ord(target[len(ans)]) - ord('a')

            for k in range(j + 1, 26):
                if freq[k] > 0:
                    res = ''.join(ans)
                    res += chr(k + ord('a'))
                    freq[k] -= 1

                    for x in range(26):
                        res += chr(x + ord('a')) * freq[x]

                    return res

        for i in range(len(ans) - 1, -1, -1):
            j = ord(ans[i]) - ord('a')
            freq[j] += 1

            for k in range(j + 1, 26):
                if freq[k] > 0:
                    res = ''.join(ans[:i])
                    res += chr(k + ord('a'))
                    freq[k] -= 1

                    for x in range(26):
                        res += chr(x + ord('a')) * freq[x]

                    return res

        return ""