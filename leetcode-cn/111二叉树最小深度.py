# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        left, right = self.minDepth(root.left), self.minDepth(root.right)
        return 1+min(left, right) if left and right else 1+left+right
