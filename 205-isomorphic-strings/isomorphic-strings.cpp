class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> maps;
        unordered_map<char, bool> cp;

        for(int i = 0; i < s.size(); i++){
            if(!maps.count(s[i])){
                if(!cp[t[i]]){
                    cp[t[i]] = true;
                    maps[s[i]] = t[i];
                }else{
                    return false;
                }
            }else{
                if(t[i] != maps[s[i]]){
                    return false;
                }
            }
        }

        return true;
    }
};