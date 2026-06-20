/*
LeetCode 1722 - Minimize Hamming Distance After Swap Operations

Problem:
Given two arrays source and target and a list of allowed swaps,
find the minimum possible Hamming distance between source and target
after performing any number of allowed swaps on source.

Approach:
1. Use Disjoint Set Union (DSU) to find connected components of indices.
2. Indices in the same component can be rearranged freely.
3. For each component:
   - Collect source values and target values.
   - Sort both arrays.
   - Count common values using two pointers.
4. Unmatched values contribute to the Hamming distance.

Pattern: Union Find (DSU), Graph Connectivity

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

// DSU
int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int parent[], int rank[], int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);
    if (px == py) return;

    if (rank[px] < rank[py])
        parent[px] = py;
    else if (rank[px] > rank[py])
        parent[py] = px;
    else {
        parent[py] = px;
        rank[px]++;
    }
}

// comparator for sorting indices by parent
int *gparent;
int cmpIndex(const void* a, const void* b) {
    return gparent[*(int*)a] - gparent[*(int*)b];
}

// comparator for values
int cmpVal(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minimumHammingDistance(int* source, int n, int* target, int targetSize,
                          int** allowedSwaps, int allowedSwapsSize,
                          int* allowedSwapsColSize) {

    int parent[n], rank[n];

    // init
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // union
    for (int i = 0; i < allowedSwapsSize; i++) {
        unionSet(parent, rank, allowedSwaps[i][0], allowedSwaps[i][1]);
    }

    // compress
    for (int i = 0; i < n; i++) {
        parent[i] = find(parent, i);
    }

    // sort indices by component
    int idx[n];
    for (int i = 0; i < n; i++) idx[i] = i;

    gparent = parent;
    qsort(idx, n, sizeof(int), cmpIndex);

    int mismatch = 0;

    int i = 0;
    while (i < n) {
        int j = i;

        // same component
        while (j < n && parent[idx[j]] == parent[idx[i]])
            j++;

        int size = j - i;

        // collect values
        int *s = malloc(size * sizeof(int));
        int *t = malloc(size * sizeof(int));

        for (int k = 0; k < size; k++) {
            int id = idx[i + k];
            s[k] = source[id];
            t[k] = target[id];
        }

        // sort values
        qsort(s, size, sizeof(int), cmpVal);
        qsort(t, size, sizeof(int), cmpVal);

        // count matches correctly
        int p1 = 0, p2 = 0, match = 0;
        while (p1 < size && p2 < size) {
            if (s[p1] == t[p2]) {
                match++;
                p1++; p2++;
            } else if (s[p1] < t[p2]) {
                p1++;
            } else {
                p2++;
            }
        }

        mismatch += (size - match);

        free(s);
        free(t);

        i = j;
    }

    return mismatch;
}