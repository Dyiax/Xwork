class Solution:
    def sum(self, num1: int, num2: int) -> int:
        return num1 + num2
def main():
    # 创建 Solution 类的实例
    solution = Solution()
    # 接受用户输入num1和num2
    user_input = input()
    # 提取 num1 和 num2 的值
    num1, num2 = [int(x.split("=")[1].strip()) for x in user_input.split(",")]
    # 调用实例的sum方法，计算num1和num2的和
    result = solution.sum(num1, num2)
    print(result)  # 输出: 30

if __name__ == "__main__":
    main()