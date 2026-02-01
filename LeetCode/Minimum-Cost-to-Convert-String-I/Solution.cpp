1class Solution {
2public:
3    const long long INF = 1e18;
4
5    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
6        unordered_map<char, vector<pair<char, int>>> m;
7        long long ans = 0;
8
9        for(int i = 0; i < original.size(); i++){
10            m[original[i]].push_back({changed[i], cost[i]});
11        }
12
13        unordered_map<char, vector<long long>> cache;
14
15        for(int i = 0; i < source.size(); i++){
16            char s = source[i];
17            char t = target[i];
18
19            if(s == t){
20                continue;
21            }
22
23            if(!cache.count(s)){
24                cache[s] = dijkstra(s, m);
25            }
26
27            long long distance = cache[s][t-'a'];
28
29            if(distance == INF){
30                return -1;
31            }
32
33            ans+=distance;
34        }
35
36        return ans;
37    }
38
39private:
40    vector<long long> dijkstra(char start, unordered_map<char, vector<pair<char, int>>>& m){
41        vector<long long> dist(26, INF);
42        dist[start-'a'] = 0;
43
44        priority_queue<pair<char, long long>, vector<pair<char, long long>>, greater<>> pq;
45
46        pq.push({start, 0});
47
48        while(!pq.empty()){
49            auto [ch, currCost] = pq.top();
50            pq.pop();
51
52            if(dist[ch-'a'] > currCost){
53                continue;
54            }
55
56            for(auto[v, w]: m[ch]){
57                if(dist[v-'a'] > currCost + w){
58                    dist[v-'a'] = currCost + w;
59                    pq.push({v, dist[v-'a']});
60                }
61            }
62        }
63
64        return dist;
65    }
66};