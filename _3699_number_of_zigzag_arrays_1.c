/*
ZigZag Arrays

Problem:
Given an array length n and value range [l, r], count the number of arrays where
adjacent elements are different and no three consecutive elements form a strictly
increasing or strictly decreasing sequence. Return the count modulo 1e9+7.

Approach:
Use dynamic programming with two states per value:
- up[v]: number of valid arrays ending at value v where the last comparison is increasing.
- down[v]: number of valid arrays ending at value v where the last comparison is decreasing.

For length 2, initialize counts based on how many smaller/larger values can precede each value.
For each additional position, build:
- newUp[v] from all down states ending with smaller values.
- newDown[v] from all up states ending with larger values.

Prefix and suffix accumulations allow these transitions to be computed efficiently.

Pattern: Dynamic Programming

Time Complexity: O(n * (r - l + 1))
Space Complexity: O(r - l + 1)
*/


#include <stdlib.h>

#define MOD 1000000007LL

int zigZagArrays(int n, int l, int r) {
    int m = r - l + 1;

    if (n == 1)
        return m % MOD;

    long long *up = calloc(m, sizeof(long long));
    long long *down = calloc(m, sizeof(long long));

    for (int v = 0; v < m; v++) {
        up[v] = v;           
        down[v] = m - 1 - v; 
    }

    if (n == 2) {
        long long ans = 0;
        for (int v = 0; v < m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }
        free(up);
        free(down);
        return (int)ans;
    }

    for (int len = 3; len <= n; len++) {
        long long *newUp = calloc(m, sizeof(long long));
        long long *newDown = calloc(m, sizeof(long long));

        long long prefix = 0;
        for (int v = 0; v < m; v++) {
            newUp[v] = prefix;
            prefix = (prefix + down[v]) % MOD;
        }

        long long suffix = 0;
        for (int v = m - 1; v >= 0; v--) {
            newDown[v] = suffix;
            suffix = (suffix + up[v]) % MOD;
        }

        free(up);
        free(down);

        up = newUp;
        down = newDown;
    }

    long long ans = 0;
    for (int v = 0; v < m; v++) {
        ans = (ans + up[v] + down[v]) % MOD;
    }

    free(up);
    free(down);

    return (int)ans;
}