class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        for(int i = 1; i <= n; i++){
            if(check(i)){
                count++;
            }
        }

        return count;
    }

private:
    bool check(int n){
        bool check = false;

        //  for(int i = 1; i <= n; i++){
            int temp = n;

            while(temp > 0){
                int dig = temp%10;

                if(dig == 3 || dig == 4 || dig == 7){
                    return false;
                }

                if(dig == 2 || dig == 5 || dig == 6 || dig == 9){
                    check = true;
                    // break;
                }

                temp/=10;
            }

            return check;
    }
};