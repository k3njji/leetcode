class Solution {
public:
    int mirrorDistance(int n) {
        int prevese = n;
        int reverse = 0;

        while(n > 0){
            reverse*=10;
            int temp = n%10;
            reverse += temp;
            // cout << reverse << endl;
            n = n/10;
        }

        return abs(prevese - reverse);
    }
};