class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        res = set()

        def backtrack(build, curr):
            
            key = tuple(sorted(build))
            if len(build) <= len(nums) and key not in res:
                ans.append(build)
                res.add(key)
            
            for i in range(curr, len(nums)):
                backtrack(build + [nums[i]], i + 1)

        backtrack([], 0)
        return ans