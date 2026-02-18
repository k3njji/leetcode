class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> sol;
         for(int i = 0; i < equations.size(); i++){
            sol[equations[i][0]].push_back({equations[i][1], values[i]});
            sol[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        // for(auto& s: sol){
        //     auto& key = s.first;
        //     auto& edges = s.second;

        //     cout << key << " -> ";
        //     for(auto& [neighbor, weight]: edges){
        //         cout << "(" << neighbor << ", " << weight << ") ";
        //     }
        //     cout << endl;
        // }
        
        vector<double> ans;
        for(int i = 0; i < queries.size(); i++){
            unordered_set<string> visited;
            ans.push_back(dfs(queries[i][0], queries[i][1], visited, sol, 1));
        }

        return ans;
    }

private:
    double dfs(string start, string end, unordered_set<string>& visited, unordered_map<string, vector<pair<string, double>>>& sol, double res){
        if(!sol.count(start) || !sol.count(end)){
            return -1;
        }

        if(start == end){
            return res;
        }

        visited.insert(start);

        for(auto& [n, w]: sol[start]){
            if(visited.count(n)){
                continue;
            }

            double temp = dfs(n, end, visited, sol, w*res);

            if(temp!=-1){
                return temp;
            }
        }

        return -1;
    }

};