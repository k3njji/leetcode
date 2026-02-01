class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> dup_num = nums;
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size()-1;
        int a;
        int b;

        while(left < right){
            if(nums[left] + nums[right] > target){
                right--;
            }else if(nums[left] + nums[right] < target){
                left++;
            }else{
                a = nums[left];
                b = nums[right];
                break;
            }
        }

        int idx1 = -1;
        int idx2 = -1;

        for(int i = 0; i < nums.size(); i++){
            if(a == dup_num[i] && idx1 == -1){
                idx1 = i;
            }else if(b == dup_num[i] && idx2 == -1){
                idx2 = i;
            }
        }

        return {idx1, idx2};
    }
};