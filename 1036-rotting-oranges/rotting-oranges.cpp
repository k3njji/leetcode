class Solution {
public:

struct DataPoint {
    int val1;
    int val2;
    int val3;

    // Constructor for convenience
    DataPoint(int v1, int v2, int v3) : val1(v1), val2(v2), val3(v3) {}

    // Overload the < operator to define priority.
    // This example creates a max-heap based on val1 (highest val1 has highest priority).
    bool operator<(const DataPoint& other) const {
        return val1 > other.val1; 
    }
};

    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0;

        int flag = true;

        priority_queue<DataPoint> pq;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    pq.push(DataPoint(minute, i, j));
                }
            }
        }

        bfs(grid, pq, minute);

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if( grid[i][j] == 1 ){
                    flag = false;
                    break;
                }
            }
        }

        return (flag) ? minute : -1;
    }

private:
    void bfs(vector<vector<int>>& grid, priority_queue<DataPoint>& pq, int& minute){
        if (pq.empty()) return;

        DataPoint tops = pq.top();

        minute = tops.val1;
            
        int top = tops.val2-1;
        int bot = tops.val2+1;
        int left = tops.val3-1;
        int right = tops.val3+1;

        if( top >= 0 && grid[top][tops.val3] == 1 ){
            grid[top][tops.val3] = 2;
            pq.push(DataPoint(minute+1, top, tops.val3));
        }
        if( bot < grid.size() && grid[bot][tops.val3] == 1 ){
            grid[bot][tops.val3] = 2;
            pq.push(DataPoint(minute+1, bot, tops.val3));
        }

        if( left >= 0 && grid[tops.val2][left] == 1 ){
            grid[tops.val2][left] = 2;
            pq.push(DataPoint(minute+1, tops.val2, left));
        }

        if( right < grid[tops.val2].size() && grid[tops.val2][right] == 1 ){
            grid[tops.val2][right] = 2;
            pq.push(DataPoint(minute+1, tops.val2, right));
        }
            
        pq.pop();
    

        bfs(grid, pq, minute);
    }
};