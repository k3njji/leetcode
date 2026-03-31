class Solution:
    def countArrangement(self, n: int) -> int:
        count = 0

        def btrack(build):
            nonlocal count

            if len(build) == n:
                count += 1
                return
            
            for i in range(1, n+1):
                if i not in build:
                    pos = len(build) + 1
                    if i % pos == 0 or pos % i == 0:
                        btrack(build + [i])
        
        btrack([])
        return count