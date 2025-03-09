class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        product = 1
        sum = 0
        for digit in str(n):
            product *= int(digit)
            sum += int(digit)
        return product - sum

def main():
    solution = Solution()
    # user_input = int (input())
    result1 = solution.subtractProductAndSum(234)
    result2 = solution.subtractProductAndSum(4421)
    print(result1)
    print(result2)

if __name__ == "__main__":
    main()

