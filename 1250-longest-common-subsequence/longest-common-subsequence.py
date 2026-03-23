class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        word1 = len(text1)
        word2 = len(text2)
        arr = [[0 for _ in range(word2 + 1)] for _ in range(word1 + 1)]
        for i in range(1, word1+1):
            for j in range(1, word2+1):
                if(text1[i-1] == text2[j-1]):
                    arr[i][j] = arr[i-1][j-1] + 1
                else:
                    arr[i][j] = max(arr[i-1][j], arr[i][j-1])
        return arr[word1][word2]
