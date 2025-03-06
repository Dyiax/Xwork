# 给定一个长度为 n 的整数 山脉 数组 arr ，其中的值递增到一个 峰值元素 然后递减。

# 返回峰值元素的下标。

# 你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。

 

# 示例 1：

# 输入：arr = [0,1,0]
# 输出：1
# 示例 2：

# 输入：arr = [0,2,1,0]
# 输出：1
# 示例 3：

# 输入：arr = [0,10,5,2]
# 输出：1
from typing import List

class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        left = 0
        right = len(arr) - 1
        while left < right:
            mid = (left + right) // 2
            if arr[mid] < arr[mid + 1]:
                left = mid + 1
            else:
                right = mid
        return left
def main():
    solution = Solution()
    print(solution.peakIndexInMountainArray([0,1,0]))
    print(solution.peakIndexInMountainArray([0,2,1,0]))
    print(solution.peakIndexInMountainArray([0,10,5,2]))

if __name__ == "__main__":
    main()