from typing import List
class Solution:
    # def vowelStrings(self, words: List[str], left: int, right: int) -> int:
    #     vowels = set("aeiou")
    #     if left == right:
    #         return sum(1 for c in words[left] if c in vowels)
    #     mid = (left + right) // 2
    #     return self.vowelStrings(words, left, mid) + self.vowelStrings(words, mid + 1, right)
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        vowels = set("aeiou")
        sum = 0
        for i in range(left, right + 1):
            word = words[i]
            if word and word[0].lower() in vowels and word[-1].lower() in vowels:
                sum += 1
        return sum
    
def main():
    solution = Solution()
    #print("hello")
    print(solution.vowelStrings(["are","amy","u"], 0, 2))
    print(solution.vowelStrings(["hey","aeo","mu","ooo","artro"], 1, 4))
    
if __name__ == "__main__":
    main()