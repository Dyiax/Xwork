class Solution:
    def toLowerCase(self, s: str) -> str:
        return s.lower()
    
def main():
    solution = Solution()
    user_input = input()
    result = solution.toLowerCase(user_input)
    print(result)

if __name__ == "__main__":
    main()
    