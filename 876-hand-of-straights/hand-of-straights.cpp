class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0){
            return false;
        }

        map<int, int> save;
        int count = 0;
        for (int i = 0; i < hand.size(); i++){
            save[hand[i]]++;
            count++;
        }
        
        int counter = 0;

        while(count > 0){
            counter = 0;
            int start = -1;
            for(auto& pair : save){
                if(pair.second > 0){
                    start = pair.first;
                    break;
                }
            }

            if(start == -1){
                return false;
            }

            for(int i = 0; i < groupSize; i++){
                int curr = start + i;

                if(save[curr] <= 0){
                    return false;
                }

                save[curr]--;   
                count--;
                counter++;
            }
        }

        return true;
    }
};