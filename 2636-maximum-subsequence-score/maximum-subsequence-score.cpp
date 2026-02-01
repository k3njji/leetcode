class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<long long int, long long int>> pq;

        for(int i = 0; i < nums2.size(); i++){
            pq.push({nums2[i], nums1[i]});
        }

        priority_queue<int, vector<int>, greater<int>> keep;

        long long total = 0;
        long long ans = 0;

        while(!pq.empty()){
            auto [n2, n1] = pq.top();
            pq.pop();

            total += n1;
            keep.push(n1);

            if(keep.size() > k){
                total -= keep.top();
                keep.pop();
            }

            if(keep.size() == k){
                ans = max(ans, total * n2);
            }
        }

        return ans;
    }
};