class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> ans;

        while(n>=2){
            n = calculate(n);
            if(ans[n] == true){
                return false;
            }
            ans[n] = true;
        }

        return true;
    }

private:
    int calculate(int n){
        int sum = 0;

        while(n!=0){
            int temp = n%10;
            n/=10;
            sum += temp*temp;
        }

        return sum;
    }
};