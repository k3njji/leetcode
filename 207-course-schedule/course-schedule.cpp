class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;

        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            if(state[i] == 0){
                if(!traverse(graph, i, state)){
                    return false;
                }
            }
        }

        return true;
    }

    bool traverse(unordered_map<int, vector<int>>& graph, int data, vector<int>& state){

        if(state[data] == 1) return false;
        if(state[data] == 2) return true;

        state[data] = 1;

        for(const auto& vis : graph[data]){
            if(!traverse(graph, vis, state)){
                return false;
            }
        }

        state[data] = 2;
        return true;
    }
};