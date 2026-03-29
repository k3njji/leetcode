class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []

        def dfs(build, curr):
            if(len(build) == k):
                ans.append(build)
                return

            for i in range (curr, n+1):
                dfs(build+[i], i+1)

        dfs([], 1)

        return ans
                