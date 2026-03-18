class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        output = []
        candidates.sort()

        def dfs(build, current):
            if sum(build) == target:
                output.append(build)
                return
            if sum(build) > target:
                return

            for i in range(current, len(candidates)):
                if i > current and candidates[i] == candidates[i-1]:
                    continue

                dfs(build + [candidates[i]], i+1)

        dfs([], 0)
        return output