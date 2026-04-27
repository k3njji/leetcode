class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<bool>> ans(
            grid.size(),
            vector<bool>(grid[0].size(), false)
        );

        traverse(grid, ans, 0, 0);

        return ans[grid.size() - 1][grid[0].size() - 1];
    }

private:
    void traverse(const vector<vector<int>>& grid,
                  vector<vector<bool>>& ans,
                  int i,
                  int j) {
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size() ||
            ans[i][j]) {
            return;
        }

        ans[i][j] = true;

        if (grid[i][j] == 1) {
            if (j + 1 < grid[0].size() &&
                (grid[i][j + 1] == 1 ||
                 grid[i][j + 1] == 3 ||
                 grid[i][j + 1] == 5)) {
                traverse(grid, ans, i, j + 1);
            }

            if (j - 1 >= 0 &&
                (grid[i][j - 1] == 1 ||
                 grid[i][j - 1] == 4 ||
                 grid[i][j - 1] == 6)) {
                traverse(grid, ans, i, j - 1);
            }

        } else if (grid[i][j] == 2) {
            if (i + 1 < grid.size() &&
                (grid[i + 1][j] == 2 ||
                 grid[i + 1][j] == 5 ||
                 grid[i + 1][j] == 6)) {
                traverse(grid, ans, i + 1, j);
            }

            if (i - 1 >= 0 &&
                (grid[i - 1][j] == 2 ||
                 grid[i - 1][j] == 3 ||
                 grid[i - 1][j] == 4)) {
                traverse(grid, ans, i - 1, j);
            }

        } else if (grid[i][j] == 3) {
            if (j - 1 >= 0 &&
                (grid[i][j - 1] == 1 ||
                 grid[i][j - 1] == 4 ||
                 grid[i][j - 1] == 6)) {
                traverse(grid, ans, i, j - 1);
            }

            if (i + 1 < grid.size() &&
                (grid[i + 1][j] == 2 ||
                 grid[i + 1][j] == 5 ||
                 grid[i + 1][j] == 6)) {
                traverse(grid, ans, i + 1, j);
            }

        } else if (grid[i][j] == 4) {
            if (j + 1 < grid[0].size() &&
                (grid[i][j + 1] == 1 ||
                 grid[i][j + 1] == 3 ||
                 grid[i][j + 1] == 5)) {
                traverse(grid, ans, i, j + 1);
            }

            if (i + 1 < grid.size() &&
                (grid[i + 1][j] == 2 ||
                 grid[i + 1][j] == 5 ||
                 grid[i + 1][j] == 6)) {
                traverse(grid, ans, i + 1, j);
            }

        } else if (grid[i][j] == 5) {
            if (j - 1 >= 0 &&
                (grid[i][j - 1] == 1 ||
                 grid[i][j - 1] == 4 ||
                 grid[i][j - 1] == 6)) {
                traverse(grid, ans, i, j - 1);
            }

            if (i - 1 >= 0 &&
                (grid[i - 1][j] == 2 ||
                 grid[i - 1][j] == 3 ||
                 grid[i - 1][j] == 4)) {
                traverse(grid, ans, i - 1, j);
            }

        } else if (grid[i][j] == 6) {
            if (j + 1 < grid[0].size() &&
                (grid[i][j + 1] == 1 ||
                 grid[i][j + 1] == 3 ||
                 grid[i][j + 1] == 5)) {
                traverse(grid, ans, i, j + 1);
            }

            if (i - 1 >= 0 &&
                (grid[i - 1][j] == 2 ||
                 grid[i - 1][j] == 3 ||
                 grid[i - 1][j] == 4)) {
                traverse(grid, ans, i - 1, j);
            }
        }
    }
};