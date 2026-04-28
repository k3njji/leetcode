class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:

        save = {}

        def dfs(temp: int):
            
            if temp == amount:
                return 0
            if temp > amount:
                return -1
            if temp in save:
                return save[temp]

            ans = -1

            for i in range(len(coins)):

                curr = dfs(temp + coins[i])

                if curr != -1:
                    if ans == -1:
                        ans = curr + 1
                    elif ans > curr + 1:
                        ans = curr + 1

            save[temp] = ans
            return ans

        return dfs(0)