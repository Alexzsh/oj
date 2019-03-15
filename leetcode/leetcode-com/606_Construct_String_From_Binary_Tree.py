class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def tree2str(self, t: TreeNode) -> str:
        if t == None:
            return ''
        return '{}{}{}'.format(
            t.val,
            '('+self.tree2str(t.left) +
            ')' if t.left != None else '()' if t.right != None else '',
            '('+self.tree2str(t.right)+')' if t.right != None else ''
        )
if __name__ == '__main__':
    a,b,c,d = map(lambda x: TreeNode(x),range(1,5))
    a.left = b
    b.right = d
    a.right = c
    print(Solution().tree2str(a)) 
    
