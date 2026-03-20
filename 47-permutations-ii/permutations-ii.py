class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        used = [False] * len(nums)

        def backtrack(build):
            if len(build) == len(nums):
                ans.append(build)
                return

            for i in range(len(nums)):
                if used[i]:
                    continue

                if i > 0 and nums[i] == nums[i-1] and not used[i-1]:
                    continue

                used[i] = True
                backtrack(build + [nums[i]])
                used[i] = False

        backtrack([])
        return ans