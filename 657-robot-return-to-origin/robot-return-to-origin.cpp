class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> tempo;

        for(auto const& mov: moves){
            if(mov == 'U'){
                if(tempo['D'] >= 1){
                    tempo['D']--;
                }else{
                    tempo[mov]++;
                }
            }

            else if(mov == 'D'){
                if(tempo['U'] >= 1){
                    tempo['U']--;
                }else{
                    tempo[mov]++;
                }
            }

            else if(mov == 'L'){
                if(tempo['R'] >= 1){
                    tempo['R']--;
                }else{
                    tempo[mov]++;
                }
            }

            else if(mov == 'R'){
                if(tempo['L'] >= 1){
                    tempo['L']--;
                }else{
                    tempo[mov]++;
                }
            }
        }

        for (const auto& pair: tempo){
            if(pair.second > 0){
                return false;
            }
        }

        return true;
    }
};