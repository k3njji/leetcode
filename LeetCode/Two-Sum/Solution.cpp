1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        vector<int> dup_num = nums;
5        sort(nums.begin(), nums.end());
6
7        int left = 0;
8        int right = nums.size()-1;
9        int a;
10        int b;
11
12        while(left < right){
13            if(nums[left] + nums[right] > target){
14                right--;
15            }else if(nums[left] + nums[right] < target){
16                left++;
17            }else{
18                a = nums[left];
19                b = nums[right];
20                break;
21            }
22        }
23
24        int idx1 = -1;
25        int idx2 = -1;
26
27        for(int i = 0; i < nums.size(); i++){
28            if(a == dup_num[i] && idx1 == -1){
29                idx1 = i;
30            }else if(b == dup_num[i] && idx2 == -1){
31                idx2 = i;
32            }
33        }
34
35        return {idx1, idx2};
36    }
37};