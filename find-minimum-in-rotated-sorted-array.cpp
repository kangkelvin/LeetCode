class Solution {
public:
    int findMin(vector<int>& nums) {        
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            // if low is smaller than high, then array is sorted normally
            // return low
            if (nums[low] <= nums[high]) {
                return nums[low];
            }
            
            if (low + 1 == high) {
                return std::min(nums[low], nums[high]);
            }
            
            // else, this is the abnormal case, array is rotated
            int mid = low + (high - low) / 2;
            
            if (nums[mid] > nums[low]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return -1;
    }
};
