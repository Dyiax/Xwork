class Solution:
    def addDigits(self, num: int) -> int:
        while num > 9:
            num = sum([int(i) for i in str(num)])
        return num

def main():
    solution = Solution()
    #user_input = int(input())
    result = solution.addDigits(38)
    result2 = solution.addDigits(0)
    print(result)
    print(result2)

if __name__ == "__main__":
    main()
