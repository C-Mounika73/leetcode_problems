/*
LeetCode 2812 - Find the Safest Path in a Grid

Problem:
Given an n x n grid containing thieves, find a path from (0,0) to (n-1,n-1) that maximizes the minimum Manhattan distance from any cell on the path to the nearest thief. Return the maximum possible safeness factor.

Approach:
First, perform a multi-source BFS starting from all thief cells to compute the minimum distance from every cell to its nearest thief. Then, use binary search on the possible safeness factor. For each candidate value, run a BFS to check whether a path exists using only cells whose distance to the nearest thief is at least that value. The largest feasible value is the answer.

Pattern: Multi-Source BFS + Binary Search + Graph Traversal

Time Complexity: O(n² log n)
Space Complexity: O(n²)
*/


#define MAXN 400
#define INF 1000000000

typedef struct {
    int x, y;
} Node;

int dist[MAXN][MAXN];
int vis[MAXN][MAXN];
Node q[MAXN * MAXN];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int canReach(int n, int limit) {
    if (dist[0][0] < limit)
        return 0;

    memset(vis, 0, sizeof(vis));

    int front = 0, rear = 0;
    q[rear++] = (Node){0, 0};
    vis[0][0] = 1;

    while (front < rear) {
        Node cur = q[front++];

        if (cur.x == n - 1 && cur.y == n - 1)
            return 1;

        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            if (vis[nx][ny])
                continue;

            if (dist[nx][ny] < limit)
                continue;

            vis[nx][ny] = 1;
            q[rear++] = (Node){nx, ny};
        }
    }

    return 0;
}

int maximumSafenessFactor(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = INF;

    int front = 0, rear = 0;

    // Multi-source BFS from all thieves
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                dist[i][j] = 0;
                q[rear++] = (Node){i, j};
            }
        }
    }

    while (front < rear) {
        Node cur = q[front++];

        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            if (dist[nx][ny] > dist[cur.x][cur.y] + 1) {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q[rear++] = (Node){nx, ny};
            }
        }
    }

    int maxDist = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist[i][j] > maxDist)
                maxDist = dist[i][j];

    int low = 0, high = maxDist, ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canReach(n, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}