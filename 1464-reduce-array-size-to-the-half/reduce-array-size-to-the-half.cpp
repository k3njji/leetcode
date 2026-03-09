class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> temp;
        int ans = arr.size();

        for(int i = 0 ; i < ans; i++){
            temp[arr[i]]++;
        }

        priority_queue<pair<int, int>> max_pq;

        for(const auto& iter: temp){
            cout << iter.first << iter.second << endl;
            max_pq.push({iter.second, iter.first});
        }

        int half = ans/2;
        int count = 0;

        while(ans > half){
        cout << max_pq.top().first << max_pq.top().second << endl;
            ans -= max_pq.top().first;
            max_pq.pop();
            count++;
        }

        

        return count;
    }
};