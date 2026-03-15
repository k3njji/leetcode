class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));

        for(int i = 0; i < guards.size(); i++){
            matrix[guards[i][0]][guards[i][1]] = 2;
        }

        for(int i = 0; i < walls.size(); i++){
            matrix[walls[i][0]][walls[i][1]] = 3;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // if(matrix[i])
                if(matrix[i][j] == 2){
                    // matrix[i][j] = 1;
                    traverseSouth(matrix, i+1, j, m, n);
                    traverseNorth(matrix, i-1, j, m, n);
                    traverseWest(matrix, i, j-1, m, n);
                    traverseEast(matrix, i, j+1, m , n);
                }
                // cout << matrix[i][j] << " ";
            }
            // cout << endl;
        }

        // cout << "est" << endl;

        int ans = 0;

        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // cout << matrix[i][j] << " ";

                if(matrix[i][j] == 0){
                    ans++;
                }
                // cout << matrix[i][j] << " ";
            }
            // cout << endl;
        }

        return ans;
    }

private:
    void traverseSouth(vector<vector<int>>& matrix, int i, int j, int m, int n){
        if(i == m || matrix[i][j] == 3 || matrix[i][j] == 2){
            return;
        }
        matrix[i][j] = 1;
        traverseSouth(matrix, i+1, j, m, n);
    }

    void traverseNorth(vector<vector<int>>& matrix, int i, int j, int m, int n){
        if(i == -1 || matrix[i][j] == 3 || matrix[i][j] == 2){
            return;
        }
        matrix[i][j] = 1;
        traverseNorth(matrix, i-1, j, m, n);
    }

    void traverseEast(vector<vector<int>>& matrix, int i, int j, int m, int n){
        if(j == n || matrix[i][j] == 3 || matrix[i][j] == 2){
            return;
        }
        matrix[i][j] = 1;
        traverseEast(matrix, i, j+1, m, n);
    }

    void traverseWest(vector<vector<int>>& matrix, int i, int j, int m, int n){
        if(j == -1 || matrix[i][j] == 3 || matrix[i][j] == 2){
            return;
        }
        matrix[i][j] = 1;
        traverseWest(matrix, i, j-1, m, n);
    }
};