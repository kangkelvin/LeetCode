/////////////////// LIBRARY ANSWER ////////////////////
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {      
        vector<int> ans;
        
        int startPos, endPos;

        if (!std::binary_search(nums.begin(), nums.end(), target)) {
            startPos = endPos = -1;
        } else {
            startPos = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            endPos = std::upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;            
        }

        ans.push_back(startPos);
        ans.push_back(endPos);
        return ans;
    }
};
