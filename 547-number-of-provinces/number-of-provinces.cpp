class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<bool>visit(isConnected.size(), false);

        for(int i = 0; i < isConnected.size(); i++){
            if(!visit[i]){
                dfs(isConnected, visit, i);
                count++;
            }
        }

        return count;
    }

private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visit, int index){
        visit[index] = true;

        for(int i = 0; i < isConnected.size(); i++){
            if(!visit[i] && isConnected[index][i] == 1){
                dfs(isConnected, visit, i);
            }
        }
    }
};