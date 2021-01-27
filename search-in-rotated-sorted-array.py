// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution:
    def binarySearch(self, nums, low, high, target):
        if high >= low:
            mid = low + (high - low) // 2
            # print('%d %d %d' % (low, mid, high))

            # success case
            if nums[mid] == target:
                return mid
            elif nums[high] == target:
                return high
            elif nums[low] == target:
                return low
            else:
                if nums[low] < nums[high]:
                    if nums[mid] > target:
                        # print("case 1")
                        return self.binarySearch(nums, low, mid-1, target)
                    else:
                        # print("case 2")
                        return self.binarySearch(nums, mid+1, high, target)
                else:
                    if nums[low] < nums[mid]:
                        if nums[low] <= target and target <= nums[mid]:
                            # print("case 3")
                            return self.binarySearch(nums, low, mid-1, target)
                        else:
                            # print("case 4")
                            return self.binarySearch(nums, mid+1, high, target)
                    else:
                        if target >= nums[mid] and nums[high] >= target:
                            # print("case 5")
                            return self.binarySearch(nums, mid+1, high, target)
                        else:
                            # print("case 6")
                            return self.binarySearch(nums, low, mid-1, target)
        else:
            # print("case -1")
            return -1

    def search(self, nums: List[int], target: int) -> int:
        return self.binarySearch(nums, 0, len(nums)-1, target)
        
