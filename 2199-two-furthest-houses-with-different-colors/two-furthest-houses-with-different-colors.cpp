class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left = 0;
        int right = colors.size()-1;
        int ans = 0;

        while(left < right){
            if(colors[left] == colors[right]){
                right--;
            }else{
                ans = right - left;
                break;
            }
        }

        left = 0;
        right = colors.size()-1;

        while(left < right){
            if(colors[left] == colors[right]){
                left++;
            }else{
                if(ans < right - left){
                    ans = right - left;
                }
                break;
            }
        }

        return ans;
    }
};