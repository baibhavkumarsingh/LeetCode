class Solution {
    bool isVisited[301][301];  // Fixed size for LeetCode constraints
    
    // DFS: mark entire island as visited from (i,j)
    void rec(vector<vector<char>>& grid, int i, int j, int m, int n) {
        // Bounds check
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
        // Already visited
        if (isVisited[i][j] == true)
            return;
            
        isVisited[i][j] = true;  // Mark current cell
        
        // Explore 4 directions if neighbor is land
        if (i > 0 && grid[i - 1][j] == '1')      // Up
            rec(grid, i - 1, j, m, n);
        if (j > 0 && grid[i][j - 1] == '1')      // Left
            rec(grid, i, j - 1, m, n);
        if (i < (m - 1) && grid[i + 1][j] == '1') // Down
            rec(grid, i + 1, j, m, n);
        if (j < (n - 1) && grid[i][j + 1] == '1') // Right
            rec(grid, i, j + 1, m, n);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int answer = 0;
        
        memset(isVisited, false, sizeof(isVisited));  // Initialize visited
        
        // Scan grid: new island found → DFS entire island
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && isVisited[i][j] == false) {
                    answer++;           // New island discovered
                    rec(grid, i, j, m, n); // Mark entire island
                }
            }
        }
        return answer;
    }
};