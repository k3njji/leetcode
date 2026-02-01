class Solution {
public:
    int findClosest(int x, int y, int z) {
        int XZ = abs(x-z);
        int YZ = abs(y-z);

        if(XZ == YZ){
            return 0;
        }else if(XZ < YZ){
            return 1;
        }else{
            return 2;
        }
    }
};