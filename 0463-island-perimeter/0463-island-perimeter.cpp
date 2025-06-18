class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int totalStrides = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    totalStrides += 4;

                    // Check right neighbor
                    if (j + 1 < c && grid[i][j + 1] == 1)
                        totalStrides -= 2;

                    // Check bottom neighbor
                    if (i + 1 < r && grid[i + 1][j] == 1)
                        totalStrides -= 2;
                }
            }
        }

        return totalStrides;
    }
};
