class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        ans = []
        
        digit_to_letters = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz',
        }

        def backtrack(build, cur):
            if(len(build) == len(digits)):
                ans.append(build)
                return
            
            for alp in digit_to_letters[digits[cur]]:
                backtrack(build+alp, cur+1)

        backtrack("", 0)
                

        return ans