class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        if root == None:
            return False
        queue = [root]
        res = []


        while len(queue) > 0:
            res.extend(queue)
            for i in range(len(queue)):
                z = queue.pop(0)
                if z != None:
                    queue.extend([z.left, z.right])
            q=[]
            for i in queue:
                q.append(i.val if i!=None else -1)

            if x in q and y in q:
                index_x = len(res)+q.index(x)+1
                index_y = len(res)+q.index(y)+1
                if min(index_x, index_y) % 2 == 0 and max(index_x, index_y)-min(index_x, index_y) == 1:
                    return False
                else:
                    return True
        return False
if __name__ == '__main__':
    a,b,c,d,e = map(lambda x: TreeNode(x),range(1,6))
    a.left = b
    a.right = c
    b.right = d
    c.right = e
    print(Solution().isCousins(a,5,4))
    
