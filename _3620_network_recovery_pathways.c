/*
LeetCode 3418 - Maximum Path Score in a DAG

Problem:
Given a directed acyclic graph where some nodes may be offline, find a valid path from node 0 to node n-1 such that all intermediate nodes are online, the total edge cost does not exceed k, and the minimum edge cost along the path is maximized.

Approach:
First, compute a topological ordering of the DAG using Kahn's algorithm. Then perform binary search on the answer (minimum allowed edge cost). For each candidate value, run dynamic programming over the topological order to compute the minimum total cost to each node while ignoring offline intermediate nodes and edges with cost below the candidate threshold. If the destination can be reached within budget k, the candidate is feasible.

Pattern: Binary Search + Topological Sort + Dynamic Programming on DAG

Time Complexity: O((n + m) log W)
Space Complexity: O(n + m)

*/





#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

typedef long long ll;

typedef struct {
    int to;
    int cost;
    int next;
} Edge;

#define MAXN 50005
#define MAXM 100005
#define INF 0x3f3f3f3f3f3f3f3fLL

Edge e[MAXM];
int head[MAXN], indeg[MAXN], topo[MAXN];
ll dist[MAXN];
int idx;

void addEdge(int u, int v, int w) {
    e[idx].to = v;
    e[idx].cost = w;
    e[idx].next = head[u];
    head[u] = idx++;
}

bool check(int n, bool *online, ll k, int limit) {
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[0] = 0;

    for (int i = 0; i < n; i++) {
        int u = topo[i];

        if (dist[u] == INF)
            continue;

        if (u != 0 && u != n - 1 && !online[u])
            continue;

        for (int j = head[u]; j != -1; j = e[j].next) {
            int v = e[j].to;

            if (e[j].cost < limit)
                continue;

            if (v != n - 1 && !online[v])
                continue;

            if (dist[v] > dist[u] + e[j].cost)
                dist[v] = dist[u] + e[j].cost;
        }
    }

    return dist[n - 1] <= k;
}

int findMaxPathScore(int** edges, int edgesSize, int* edgesColSize,
                     bool* online, int onlineSize, long long k) {

    int n = onlineSize;

    memset(head, -1, sizeof(int) * n);
    memset(indeg, 0, sizeof(int) * n);
    idx = 0;

    int low = INT_MAX;
    int high = 0;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        addEdge(u, v, w);
        indeg[v]++;

        if (w < low) low = w;
        if (w > high) high = w;
    }

    if (edgesSize == 0)
        return -1;

    int q[MAXN];
    int front = 0, rear = 0;
    int deg[MAXN];

    memcpy(deg, indeg, sizeof(int) * n);

    for (int i = 0; i < n; i++)
        if (deg[i] == 0)
            q[rear++] = i;

    int t = 0;

    while (front < rear) {
        int u = q[front++];
        topo[t++] = u;

        for (int j = head[u]; j != -1; j = e[j].next) {
            int v = e[j].to;
            if (--deg[v] == 0)
                q[rear++] = v;
        }
    }

    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (check(n, online, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}