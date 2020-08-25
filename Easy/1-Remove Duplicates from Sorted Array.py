class Solution:
    def swap(self, nums, pos1, pos2):
        temp = nums[pos1]
        nums[pos1] = nums[pos2]
        nums[pos2] = temp

    def removeDuplicates(self, nums) -> int:
        swap_location = 1
        if len(nums) == 0:
            return 0
        prev_key = nums[0]
        for i in range(len(nums)):
            if nums[i] <= prev_key:
                continue
            else:
                prev_key = nums[i]
                self.swap(nums, i, swap_location)
                swap_location = swap_location + 1
        return swap_location


def unit_test1():
    sol = Solution()
    input = [0,0,1,1,1,2,2,3,3,4]
    ans = sol.removeDuplicates(input)
    print(ans)
    print(input)


unit_test1()