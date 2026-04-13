class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> save;

        for(int i = 0; i < s.size(); i++){
            save[s[i]]++;
        }

        int count = 0;
        bool odd = false;

        for(auto const& pair: save){
            if(pair.second%2 == 1){
                // if(odd < pair.second){
                    count+=pair.second-1;
                    odd=true;
                // }
            }else{
                count+=pair.second;
            }
        }

        if(odd) count++;

        return count;
    }
};