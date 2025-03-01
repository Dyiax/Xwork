class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and (n & (n - 1)) == 0

def main():
    solution = Solution()
    result = solution.isPowerOfTwo(1)
    result2 = solution.isPowerOfTwo(16)
    result3 = solution.isPowerOfTwo(0)
    print(result)
    print(result2)
    print(result3)

if __name__ == "__main__":
    main()