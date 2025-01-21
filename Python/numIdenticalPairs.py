

from typing import List


class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        count = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] == nums[j]:
                    count += 1
        return count

def main():
    solution = Solution()
    #user_input = input()
    #nums = [int(x) for x in user_input.split(",")]
    nums = [1,2,3,1,1,3]
    result = solution.numIdenticalPairs(nums)
    print(result)

if __name__ == "__main__":
    main()