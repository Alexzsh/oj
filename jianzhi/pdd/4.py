# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def levelOrder(self, root: TreeNode):
        queue = [root]
        res = []
        while len(queue) > 0:
            res.append([i.val for i in queue])
            
            for i in range(len(queue)):
                x = queue.pop(0)
                if x.left != None:
                    queue.append(x.left)
                if x.right != None:
                    queue.append(x.right)
                
        return res
if __name__ == '__main__':
    a = TreeNode(3)
    b = TreeNode(9)
    c = TreeNode(20)
    e = TreeNode(15)
    f = TreeNode(7)
    a.left = b
    a.right = c
    c.left=e
    c.right = f  
    print(Solution().levelOrder(a))

    
