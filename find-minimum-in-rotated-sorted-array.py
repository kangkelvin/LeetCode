// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution:
    def binarySearch(self, nums, low, high, lowest):
        if high >= low:
            mid = low + (high - low) // 2
            lowest[0] = min(nums[low], nums[mid], nums[high], lowest[0])
            if nums[low] < nums[high]:
                if nums[mid] > lowest[0]:
                    return self.binarySearch(nums, low, mid-1, lowest)
                else:
                    return self.binarySearch(nums, mid+1, high, lowest)
            else:
                if nums[mid] > lowest[0]:
                    return self.binarySearch(nums, mid+1, high, lowest)
                else:
                    return self.binarySearch(nums, low, mid-1, lowest)
        else:
            return lowest
    
    def findMin(self, nums: List[int]) -> int:
        lowest = [5001]
        return self.binarySearch(nums, 0, len(nums) - 1, lowest)[0]
        
