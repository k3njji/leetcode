class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;

        traverse(graph, 0, vector<int>(), ans);

        return ans;
    }

private:
    void traverse(vector<vector<int>>& graph, int index, vector<int> temp, vector<vector<int>>& ans){
        temp.push_back(index);
        if(index == graph.size()-1){
            ans.push_back(temp);
            return;
        }

        // temp.push_back(index);

        for (int curr : graph[index]) {
            traverse(graph, curr, temp, ans);
        }
    }
};