class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int firstHouse = 0;
        int secondHouse = 0;

        for(int i = 0; i < nums.size(); i++){
            int curr = max(firstHouse, secondHouse + nums[i]);
            secondHouse = firstHouse;
            firstHouse = curr;
        }

        return firstHouse;
    }
};