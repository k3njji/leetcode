1class Solution {
2public:
3    int findClosest(int x, int y, int z) {
4        int XZ = abs(x-z);
5        int YZ = abs(y-z);
6
7        if(XZ == YZ){
8            return 0;
9        }else if(XZ < YZ){
10            return 1;
11        }else{
12            return 2;
13        }
14    }
15};