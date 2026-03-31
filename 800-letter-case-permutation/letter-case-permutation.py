class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        ans = []
        res = set()
        def btrack(words, curr):
            # print(words)
            if(len(words) == len(s) and words not in res):
                ans.append(words)
                res.add(words)
                return
            for i in range(curr, len(s)):
                if(s[i].isalpha()):
                    btrack(words+s[i].lower(), i+1)
                    btrack(words+s[i].upper(), i+1)
                else:
                    btrack(words+s[i], i+1)


        btrack("", 0)

        return ans
            
        