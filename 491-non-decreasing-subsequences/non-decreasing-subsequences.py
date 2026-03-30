class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        ans = []
        res = set()

        def traverse(build, curr):
            if(len(build) >= 2 and tuple(build) not in res):
                res.add(tuple(build))
                ans.append(build)
            
            for i in range(curr, len(nums)):
                if(len(build) == 0 or build[len(build)-1] <= nums[i]):
                    traverse(build + [nums[i]], i+1)
        traverse([], 0)
        
        return ans
