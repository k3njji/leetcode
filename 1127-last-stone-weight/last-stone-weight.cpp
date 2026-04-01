class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> vecs;
        int x, y;
        for(auto stone: stones){
            vecs.push(stone);
        }

        while(!vecs.empty()){
            y = vecs.top();
            vecs.pop();
            if(vecs.empty()){
                return y;
            }
            x = vecs.top();
            vecs.pop();

            if(x != y){
                y-=x;
                vecs.push(y);
            }
        }

        return 0;
    }
};