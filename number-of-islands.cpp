// https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/792/
class Solution {
public:
    
    void bfs(vector<vector<char>>& grid, std::vector<std::vector<bool>>& visited, int r, int c, int m, int n) {
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(r, c));
        visited[r][c] = true;
        while (!q.empty()) {
            auto node = q.front();
            r = node.first;
            c = node.second;
            q.pop();
            for (int i = -1; i <= 1; i += 2) {
                int nextR = r + i;
                int nextC = c;
                if (nextR >= 0 && nextR < m && nextC >= 0 && nextC < n) {
                    if (visited[nextR][nextC] == false && grid[nextR][nextC] == '1') {
                        q.push(std::make_pair(nextR, nextC));
                        visited[nextR][nextC] = true;
                    }
                }                
            }
            for (int j = -1; j <= 1; j += 2) {
                int nextR = r;
                int nextC = c + j;
                if (nextR >= 0 && nextR < m && nextC >= 0 && nextC < n) {
                    if (visited[nextR][nextC] == false && grid[nextR][nextC] == '1') {
                        q.push(std::make_pair(nextR, nextC));
                        visited[nextR][nextC] = true;
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<bool> subVisited(n, false);
        std::vector<std::vector<bool>> visited(m, subVisited);
        
        int output = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] == false && grid[i][j] == '1') {
                    bfs(grid, visited, i, j, m, n);
                    output++;
                    // std::cout << i << " " << j << "\n";
                    // for (int x = 0; x < m; ++x) {
                    //     for (int y = 0; y < n; ++y) {
                    //         std::cout << visited[x][y] << " ";
                    //     }
                    //     std::cout << "\n";
                    // }
                }
            }
        }
        return output;
    }
};
