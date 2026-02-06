class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minPq;
        int step = 0;

        bool flag = false;

        int top = entrance[0]-1;
        int bot = entrance[0]+1;
        int left = entrance[1]-1;
        int right = entrance[1]+1;

        maze[entrance[0]][entrance[1]] = '+';

        if(top >= 0 && maze[top][entrance[1]] == '.'){
            minPq.push({step+1, {top, entrance[1]}});
        }
        
        if(bot < maze.size() && maze[bot][entrance[1]] == '.'){
            minPq.push({step+1, {bot, entrance[1]}});
        }

        if(left >= 0 &&  maze[entrance[0]][left] == '.'){
            minPq.push({step+1, {entrance[0], left}});

        }

        if(right < maze[0].size() &&  maze[entrance[0]][right] == '.'){
            minPq.push({step+1, {entrance[0], right}});
        }

        while(!minPq.empty()){
            pair<int, pair<int, int>> tops = minPq.top();

            step = tops.first;
            // cout << step<< endl;

            int x = tops.second.first;
            int y = tops.second.second;

            maze[x][y] = '+';

            int top = x-1;
            int bot = x+1;
            int left = y-1;
            int right = y+1;

            if(x == 0 || x == maze.size()-1 || y == 0 || y == maze[0].size() - 1){
                flag = true;
                break;
            }

            if(top >= 0 && maze[top][y] == '.'){
                maze[top][y] = '+';
                minPq.push({step+1, {top, y}});
            }
            
            if(bot < maze.size() && maze[bot][y] == '.'){
                maze[bot][y] = '+';
                minPq.push({step+1, {bot, y}});
            }

            if(left >= 0 &&  maze[x][left] == '.'){
                maze[x][left] = '+';
                minPq.push({step+1, {x, left}});

            }

            if(right < maze[0].size() &&  maze[x][right] == '.'){
                maze[x][right] = '+';

                minPq.push({step+1, {x, right}});
            }
            minPq.pop();
        }
    
        
        if(flag){
            return step;
        }else{
            return -1;
        }
    }
};