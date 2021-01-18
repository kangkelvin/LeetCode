# https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/569/
# Python recursive
class Solution:
    def climbStairsRecursive(self, n, output, memo):
        if n in memo.keys():
            return memo[n]
        if (n == 1):
            return 1
        if (n == 2):
            return 2
        oneDecrementVal = self.climbStairsRecursive(n - 1, output, memo)
        twoDecrementVal = self.climbStairsRecursive(n - 2, output, memo)
        output = oneDecrementVal + twoDecrementVal
        if n not in memo.keys():
            memo[n] = output
        return output
    
    def climbStairs(self, n: int) -> int:
        memo = {}
        return self.climbStairsRecursive(n, 0, memo)
