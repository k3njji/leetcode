class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int size = graph.size();

        vector<int> state(size, 0); 

        for(int i = 0; i < size; i++){
            if(traverse(graph, state, i)){
                ans.push_back(i);
            }
        }

        return ans;
    }

private:
    bool traverse(vector<vector<int>>& graph, vector<int>& state, int index){

        if(state[index] == 1) return false;
        if(state[index] == 2) return true;

        state[index] = 1;

        for(const auto& vis : graph[index]){
            if(!traverse(graph, state, vis)){
                return false;
            }
        }

        state[index] = 2;
        return true;
    }
};