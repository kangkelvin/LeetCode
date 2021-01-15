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

//////////////// MANUAL //////////////////
class Solution {
public:
    int searchBound(vector<int> nums, int target, bool searchLower) {
        int low = 0;
        int high = nums.size();
        int mid;
        
        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[mid] > target || (searchLower && nums[mid] == target)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    } 
    
    vector<int> searchRange(vector<int>& nums, int target) {      
        vector<int> ans;
        
        int startPos = searchBound(nums, target, true);
        int endPos = searchBound(nums, target, false) - 1;
        
        if (startPos == nums.size() || nums[startPos] != target) {
            startPos = endPos = -1;
        }
        
        ans.push_back(startPos);
        ans.push_back(endPos);
        return ans;
    }
};
