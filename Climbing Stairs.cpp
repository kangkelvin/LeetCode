// https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/569/
class Solution {
public:
    int climbStairsRecursive(int n, std::vector<int>& memo) {
        if (memo[n] != 0) {
            return memo[n];
        }
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int oneDecrementVal = climbStairsRecursive(n - 1, memo);
        int twoDecrementVal = climbStairsRecursive(n - 2, memo);
        int output = oneDecrementVal + twoDecrementVal;
        memo[n] = output;
        return output;
    }
    
    int climbStairs(int n) {
        std::vector<int> memo(n + 1, 0);
        return climbStairsRecursive(n, memo);
    }
};
