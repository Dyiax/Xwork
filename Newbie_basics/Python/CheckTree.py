# 定义二叉树节点类
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 定义Solution类，包含checkTree方法
class Solution:
    def checkTree(self, root: TreeNode) -> bool:
        # 检查根节点值是否等于左右子节点值之和
        return root.val == root.left.val + root.right.val

# 创建测试用例
if __name__ == "__main__":
    # 创建一个符合条件的二叉树：根节点值为3，左节点为1，右节点为2
    node1 = TreeNode(1)
    node2 = TreeNode(2)
    root = TreeNode(3, node1, node2)

    # 创建Solution对象
    solution = Solution()
    
    # 调用checkTree方法进行测试
    print(solution.checkTree(root))  # 应输出True

    # 创建一个不符合条件的二叉树：根节点值为4，左节点为1，右节点为2
    root2 = TreeNode(4, node1, node2)
    
    # 再次调用checkTree方法进行测试
    print(solution.checkTree(root2))  # 应输出False