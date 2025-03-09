class Solution:
    def maxScore(self,s: str) -> int:
        max_score = 0
        left_zeros = 0#count of zeros on the left side
        right_ones = s.count('1')#count of ones on the right side
        for i in range(len(s) - 1):
            if s[i] == '0':
                left_zeros += 1
            else:
                right_ones -= 1
            #max_score = max(max_score, left_zeros + right_ones)
            if (left_zeros + right_ones) > max_score:
                max_score = left_zeros + right_ones
        return max_score

def main():
    solution = Solution()
    print(solution.maxScore("00111"))
    print(solution.maxScore("1111"))

if __name__ == "__main__":
    main()