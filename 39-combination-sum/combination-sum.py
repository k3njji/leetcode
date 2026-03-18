class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []

        def dfs(build, pos):
            if(sum(build) == target):
                ans.append(build)
                return
            if(sum(build) > target):
                return
            

            for i in range(pos, len(candidates)):
                dfs(build+[candidates[i]], i)

        dfs([], 0)

        return ans