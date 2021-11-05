class Solution {
public:
    int binarySearchRecursive(vector<int>& nums, int low, int high, int target) {       
        if (high >= low) {
            int mid = low + (high - low) / 2;
            // std::cout << low << " " << mid << " " << high << " " << nums[mid] << " " << target << std::endl;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[low] <= nums[mid]) {
                if (target < nums[low] || target > nums[mid]) {
                    return binarySearchRecursive(nums, mid + 1, high, target);
                } else {
                    return binarySearchRecursive(nums, low, mid - 1, target);
                }
            } else {
                if (target > nums[high] || target < nums[mid]) {
                    return binarySearchRecursive(nums, low, mid - 1, target);
                } else {
                    return binarySearchRecursive(nums, mid + 1, high, target);
                }
            }
        }
        else {
            return -1;
        }
    }
    
    int binarySearchIterative(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } 
            
            if (nums[low] <= nums[mid]) {
                if (target < nums[low] || target > nums[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (target > nums[high] || target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return binarySearchIterative(nums, 0, nums.size() - 1, target);
    }
};
