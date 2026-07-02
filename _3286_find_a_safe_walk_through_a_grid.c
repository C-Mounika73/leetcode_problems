/*
LeetCode 3286 - Find a Safe Walk Through a Grid

Problem:
Given a binary grid where entering an unsafe cell reduces health by 1, determine whether it is possible to reach the bottom-right cell from the top-left while maintaining a health value of at least 1 throughout the journey.

Approach:
Use BFS while storing the remaining health for each state. Maintain a `best` matrix that records the maximum remaining health with which each cell has been reached. A neighboring cell is explored only if it can be reached with more remaining health than before, preventing unnecessary revisits and ensuring efficient traversal.

Pattern: Graph Traversal (BFS)

Time Complexity: O(m × n)
Space Complexity: O(m × n)
*/


typedef struct {
    int x;
    int y;
    int health;
} Node;

bool findSafeWalk(int** grid, int gridSize, int* gridColSize, int health) {
    int m = gridSize;
    int n = gridColSize[0];

    int best[50][50];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            best[i][j] = -1;

    Node q[250000];
    int front = 0, rear = 0;

    int startHealth = health - grid[0][0];
    if (startHealth <= 0)
        return false;

    q[rear++] = (Node){0, 0, startHealth};
    best[0][0] = startHealth;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (front < rear) {
        Node cur = q[front++];

        if (cur.x == m - 1 && cur.y == n - 1)
            return true;

        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;

            int newHealth = cur.health - grid[nx][ny];

            if (newHealth <= 0)
                continue;

            if (newHealth <= best[nx][ny])
                continue;

            best[nx][ny] = newHealth;
            q[rear++] = (Node){nx, ny, newHealth};
        }
    }

    return false;
}

