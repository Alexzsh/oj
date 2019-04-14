# class Treenode:
#     def __init__(self,val):
#         self.val=val
#         self.left=None
#         self.right=None

# def func(node):
#     if not node:
#         return 0
#     return func(node.left)+func(node.right)+1
# def gunc(root):
#     return max(func(root.left),func(root.right))

if __name__ == '__main__':
    m=int(input())
    nodes=[]

    # while m != 1:
    #     a,b=map(int, input().split())
    #     nodes.append(list([b,a]))
    #     m-=1
    # sorted(nodes,key=lambda x: x(1))
    left_set=[]
    right_set=[]
    # for l,r in nodes:
    while m!=1:
        l, r = map(int, input().split())
        if l==1:
            if len(left_set)==0:
                left_set.append(r)
            else:
                right_set.append(r)
        if l in left_set:
            left_set.append(r)
        else:
            right_set.append(r)
        m-=1
    print(max(len(set(left_set),len(set(right_set)))))
    # roots=Treenode(1)
    # for son,root in nodes:
    #     r=Treenode(root)
    #     s=Treenode(son)

    
    # a=Treenode(3)
    # b=Treenode(4)
    # c = Treenode(5)
    # d = Treenode(6)
    # a.left=b
    # a.right=c
    # b.left=d
    # print(gunc(a))

    
