/*
LeetCode - ZigZag Arrays

Problem:
Count the number of arrays of length n whose values lie in the range [l, r],
where adjacent elements are different and no three consecutive elements form
a strictly increasing or strictly decreasing sequence.

Approach:
Model each value as two states:
- up[v]: sequences ending at value v with the last step increasing.
- down[v]: sequences ending at value v with the last step decreasing.

A transition is only allowed from down -> up when the previous value is smaller,
and from up -> down when the previous value is larger, ensuring the sequence
alternates direction and never contains three consecutive increasing/decreasing
elements. The transitions are represented as a matrix, and matrix exponentiation
is used to raise the transition matrix to (n - 2), allowing computation for
very large n efficiently.

Pattern: Matrix Exponentiation + Dynamic Programming

Time Complexity: O((2m)^3 * log n), where m = r - l + 1
Space Complexity: O((2m)^2)
*/


#include <stdio.h>
#include <string.h>

#define MOD 1000000007LL
#define MAXM 75
#define MAXS 150

typedef long long ll;

static ll T[MAXS][MAXS];
static ll R[MAXS][MAXS];
static ll A[MAXS][MAXS];
static ll vec[MAXS];
static ll tmpVec[MAXS];

void matMul(ll X[MAXS][MAXS], ll Y[MAXS][MAXS], ll Z[MAXS][MAXS], int sz) {
    static ll tmp[MAXS][MAXS];

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            tmp[i][j] = 0;
        }
    }

    for (int i = 0; i < sz; i++) {
        for (int k = 0; k < sz; k++) {
            if (X[i][k] == 0) continue;

            ll xik = X[i][k];

            for (int j = 0; j < sz; j++) {
                if (Y[k][j] == 0) continue;

                tmp[i][j] = (tmp[i][j] + xik * Y[k][j]) % MOD;
            }
        }
    }

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            Z[i][j] = tmp[i][j];
        }
    }
}

void matPow(ll base[MAXS][MAXS], long long exp, int sz) {
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            R[i][j] = (i == j);
        }
    }

    while (exp > 0) {
        if (exp & 1) {
            matMul(R, base, A, sz);
            memcpy(R, A, sizeof(A));
        }

        matMul(base, base, A, sz);
        memcpy(base, A, sizeof(A));

        exp >>= 1;
    }
}

int zigZagArrays(int n, int l, int r) {
    int m = r - l + 1;

    if (n == 1) return m;

    int sz = 2 * m;

    memset(T, 0, sizeof(T));

    /*
        State:
        0..m-1      => up[v]
        m..2m-1     => down[v]
    */

    for (int v = 0; v < m; v++) {

        // newUp[v] = sum down[u], u < v
        for (int u = 0; u < v; u++) {
            T[v][m + u] = 1;
        }

        // newDown[v] = sum up[u], u > v
        for (int u = v + 1; u < m; u++) {
            T[m + v][u] = 1;
        }
    }

    memset(vec, 0, sizeof(vec));

    // Initial state for length = 2
    for (int v = 0; v < m; v++) {
        vec[v] = v;           // up[v]
        vec[m + v] = m - 1 - v; // down[v]
    }

    if (n > 2) {
        matPow(T, n - 2, sz);

        memset(tmpVec, 0, sizeof(tmpVec));

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                tmpVec[i] = (tmpVec[i] + R[i][j] * vec[j]) % MOD;
            }
        }

        memcpy(vec, tmpVec, sizeof(tmpVec));
    }

    ll ans = 0;

    for (int i = 0; i < sz; i++) {
        ans = (ans + vec[i]) % MOD;
    }

    return (int)ans;
}