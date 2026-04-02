class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        count = 1

        def backtrack(build):
            nonlocal count

            if len(build) > 0:
                count += 1

            if len(build) == n:
                return
            
            for i in range(10):
                if i in build:
                    continue
                
                if len(build) == 0 and i == 0:
                    continue
                
                backtrack(build + [i])
        
        backtrack([])
        return count