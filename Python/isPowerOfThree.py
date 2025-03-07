class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n < 0:
            return False
        while (n > 1):
            if (n % 3 != 0):
                return False
            n /= 3
        return True

def main():
    solution = Solution()
    print(solution.isPowerOfThree(27))

if __name__ == "__main__":
    main()

        # The code provided is already complete and functional.
        # There is no need to add any additional code at the placeholder.