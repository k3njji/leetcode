class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        for(int i = 0; i < visited.size(); i++){
            if(visited[i] == false){
                return false;
            }
        }

        return true;
    }

private:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int s){
        visited[s] = true;

        for(auto i: rooms[s]){
            if(visited[i] == false){
                dfs(rooms, visited, i);
            }
        }

        return;
    }
};