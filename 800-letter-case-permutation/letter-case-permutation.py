class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        ans = []

        def btrack(words, curr):
            if curr == len(s):
                ans.append(words)
                return
            
            if s[curr].isalpha():
                btrack(words + s[curr].lower(), curr + 1)
                btrack(words + s[curr].upper(), curr + 1)
            else:
                btrack(words + s[curr], curr + 1)

        btrack("", 0)
        return ans