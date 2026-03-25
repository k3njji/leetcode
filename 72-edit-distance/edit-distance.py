class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        lengthOne = len(word1)
        lengthTwo = len(word2)

        if(lengthOne == 0 and lengthTwo == 0):
            return 0
        elif(lengthOne == 0):
            return lengthTwo
        elif(lengthTwo == 0):
            return lengthOne
        
        dp = [ [float('inf')] * (lengthTwo+1) for i in range(lengthOne+1)]

        for i in range(lengthTwo+1):
            dp[lengthOne][i] = lengthTwo - i

        for i in range(lengthOne+1):
            dp[i][lengthTwo] = lengthOne - i

        for i in range(lengthOne-1, -1, -1):
            for j in range(lengthTwo-1, -1, -1):
                if(word1[i] == word2[j]):
                    dp[i][j] = dp[i+1][j+1]
                else:
                    dp[i][j] = 1+min(dp[i+1][j], dp[i][j+1], dp[i+1][j+1])
        
        return dp[0][0]

        
