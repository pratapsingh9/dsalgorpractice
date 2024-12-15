class Solution(object):
    def sortArrayByParityII(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        answer = nums
        n = len(answer)
        oddidx = 1
        evenidx = 0

        while oddidx < n and evenidx < n:
            while evenidx < n and answer[evenidx] % 2 == 0:
                evenidx += 2
            while oddidx < n and answer[oddidx] % 2 == 1:
                oddidx += 2

            if evenidx < n and oddidx < n:
                nums[evenidx], nums[oddidx] = nums[oddidx], nums[evenidx]
        return answer
