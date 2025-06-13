class Solution(object):
    # def moveZeroes(self, nums):
    #     """
    #     :type nums: List[int]
    #     :rtype: None Do not return anything, modify nums in-place instead.
    #     """
        

    def moveZeroes(self,nums):
        lastNonZeroIndex = 0

    # Move all non-zero elements to the front
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[lastNonZeroIndex] = nums[i]
                lastNonZeroIndex += 1

        # Fill the remaining with zeros
        for i in range(lastNonZeroIndex, len(nums)):
            nums[i] = 0
