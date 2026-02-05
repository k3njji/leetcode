class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            int temp;
            if(i+nums[i] < 0){
                temp = ((i +nums[i])%n+n)%n;
            }else{
                temp = abs(i+nums[i])%n;
            }
            ans.push_back(nums[temp]);
        }

        return ans;
    }
};