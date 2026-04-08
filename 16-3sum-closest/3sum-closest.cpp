class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int closest = nums[0] + nums[1] + nums[2]; // initialize

        for(int i=0; i<n-2; i++){
            int left = i + 1;
            int right = n - 1;

            while(left < right){
                int temp = nums[i] + nums[left] + nums[right];

                if(abs(temp-target) < abs(closest-target)){
                    closest = temp;
                }

                if(temp == target){
                    return temp;
                }else if(temp < target){
                    left++;
                }else{
                    right--;
                }
            }
        }

        return closest;
    }
};