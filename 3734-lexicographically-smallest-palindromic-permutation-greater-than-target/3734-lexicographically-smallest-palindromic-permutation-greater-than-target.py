from collections import Counter

class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        cnt = Counter(s)

        if sum(v % 2 for v in cnt.values()) > 1:
            return ""

        half = []
        mid = ""

        for ch in sorted(cnt):
            half += [ch] * (cnt[ch] // 2)
            if cnt[ch] % 2:
                mid = ch

        m = len(half)
        target_half = target[:m]

        def make_pal(h):
            return h + mid + h[::-1]

        cnt = Counter(half)
        prefix = []

        # Find smallest half >= target_half
        for i in range(m):
            ch = target_half[i]

            if cnt[ch] > 0:
                cnt[ch] -= 1
                prefix.append(ch)
                continue

            bigger = None

            for c in sorted(cnt):
                if c > ch and cnt[c] > 0:
                    bigger = c
                    break

            if bigger is None:
                # Need to go back and increase an earlier character
                while prefix:
                    prev = prefix.pop()
                    cnt[prev] += 1

                    for c in sorted(cnt):
                        if c > prev and cnt[c] > 0:
                            cnt[c] -= 1

                            suffix = []
                            for x in sorted(cnt):
                                suffix += [x] * cnt[x]

                            h = ''.join(prefix) + c + ''.join(suffix)
                            p = make_pal(h)

                            if p > target:
                                return p

                return ""

            cnt[bigger] -= 1

            suffix = []
            for x in sorted(cnt):
                suffix += [x] * cnt[x]

            h = ''.join(prefix) + bigger + ''.join(suffix)
            return make_pal(h)

        # We matched target_half completely
        h = ''.join(prefix)
        p = make_pal(h)

        if p > target:
            return p

        # Equal half, but palindrome itself isn't greater.
        # Need the next permutation of the half.
        h = list(h)

        i = m - 2

        while i >= 0 and h[i] >= h[i + 1]:
            i -= 1

        if i < 0:
            return ""

        j = m - 1

        while h[j] <= h[i]:
            j -= 1

        h[i], h[j] = h[j], h[i]
        h[i + 1:] = reversed(h[i + 1:])

        return make_pal(''.join(h))