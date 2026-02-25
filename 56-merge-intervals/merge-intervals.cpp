class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        vector<int> temp;

        for(int i = 0; i < intervals.size(); i++){
            if(temp.size() == 0){
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
                // continue;
            }else if(intervals[i][0] <= temp[1]){
                temp[1] = max(intervals[i][1], temp[1]);
            }else{
                ans.push_back(temp);
                temp.clear();
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
            }
        }

        ans.push_back(temp);

        return ans;
    }
};