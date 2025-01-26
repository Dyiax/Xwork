from typing import List

class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        n = len(arr)
        count = 0
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    if abs(arr[i] - arr[j]) <= a and abs(arr[j] - arr[k]) <= b and abs(arr[i] - arr[k]) <= c:
                        count += 1
        return count
    

def main():
    # 创建 Solution 类的实例
    solution = Solution()
    # 接受用户输入arr, a, b, c
    user_input = input()
    # 提取 arr, a, b, c 的值
    arr = [int(x) for x in user_input.split(",")]
    a = int(input())
    b = int(input())
    c = int(input())    
    # 调用实例的countGoodTriplets方法，计算arr, a, b, c
    result = solution.countGoodTriplets(arr, a, b, c)
    print(result)  # 输出: 4

if __name__ == "__main__":
    main()
