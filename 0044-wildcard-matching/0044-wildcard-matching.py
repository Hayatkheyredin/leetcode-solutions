class Solution(object):
    def isMatch(self, s, p):
        dp = [[False] * (len(p)+1) for _ in range(len(s)+1)]
        dp[len(s)][len(p)] = True
        for i in range(len(p)-1,-1,-1):
            if p[i] == "*":
                dp[len(s)][i] = dp[len(s)][i+1]
        
        for idx1 in range(len(s)-1,-1,-1):
            for idx2 in range(len(p)-1,-1,-1):
                if (s[idx1] == p[idx2]) or (p[idx2] == "?"):
                    dp[idx1][idx2] = dp[idx1+1][idx2+1]
                elif p[idx2] == "*":
                    dp[idx1][idx2]=  dp[idx1][idx2+1] or dp[idx1+1][idx2]
                else:
                    dp[idx1][idx2] = False
        return dp[0][0]

        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        