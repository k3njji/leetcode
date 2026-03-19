class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []

        def backtrack(build, curr):
            if(len(build) > len(nums)):
                return
            
            if(len(build) <= len(nums)):
                ans.append(build)
            
            for i in range(curr, len(nums)):
                backtrack(build+[nums[i]], i+1)
        backtrack([], 0)
        return ans