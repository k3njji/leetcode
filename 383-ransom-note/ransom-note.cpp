class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mags;

        for(char c: magazine){
            mags[c]++;
        }

        for(char c: ransomNote){
            if(mags[c] == 0){
                return false;
            }
            mags[c]--;
        }

        return true;
    }
};