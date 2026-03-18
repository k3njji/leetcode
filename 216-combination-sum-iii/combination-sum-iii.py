class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:

        output = []

        def dfs(build, num):
            if(len(build) == k):
                if(sum(build) == n):
                    output.append(build)
                
                return

            for i in range(num, 9+1):
                if(sum(build) > n):
                    break
                dfs(build+[i], i+1)

        dfs([], 1)
        return output
        