class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        return (N < 0) ? 1.0/count(x, -N) : count(x, N);
    }

private:
    double count(double x, long long n){
        if(n == 0){
            return 1;
        }

        double half = count(x, n / 2);

        if(n % 2 == 0){
            return half * half;
        }

        return half * half * x;
    }
};