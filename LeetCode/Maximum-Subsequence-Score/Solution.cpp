1class Solution {
2public:
3    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
4        priority_queue<pair<long long int, long long int>> pq;
5
6        for(int i = 0; i < nums2.size(); i++){
7            pq.push({nums2[i], nums1[i]});
8        }
9
10        priority_queue<int, vector<int>, greater<int>> keep;
11
12        long long total = 0;
13        long long ans = 0;
14
15        while(!pq.empty()){
16            auto [n2, n1] = pq.top();
17            pq.pop();
18
19            total += n1;
20            keep.push(n1);
21
22            if(keep.size() > k){
23                total -= keep.top();
24                keep.pop();
25            }
26
27            if(keep.size() == k){
28                ans = max(ans, total * n2);
29            }
30        }
31
32        return ans;
33    }
34};