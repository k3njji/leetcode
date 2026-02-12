class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            unordered_map<int, int>freq;
            int unique = 0;
            int maxFreq = 0;
            for(int j = i; j < s.size(); j++){
                
                freq[s[j]-'a']++;
                if(freq[s[j]-'a'] == 1){
                    unique++;
                }
                if(maxFreq < freq[s[j]-'a']){
                    maxFreq = freq[s[j]-'a'];
                }
                int total = 0;
                int curr = j-i+1;

                for(auto& x: freq){
                    total = total+x.second;
                }

                if(total == unique*maxFreq){
                    ans = max(ans, curr);
                }
            }
        }

        return ans;
    }
};