1class Solution {
2public:
3    string triangleType(vector<int>& nums) {
4        int a = nums[0];
5        int b = nums[1];
6        int c = nums[2];
7
8        if( a+b <= c || a+c <= b || c+b <= a){
9            return "none";
10        }
11
12        if( a == b && b == c){
13            return "equilateral";
14        }
15
16        if( a == b || b == c || c == a ){
17            return "isosceles";
18        }
19
20        return "scalene";
21    }
22};