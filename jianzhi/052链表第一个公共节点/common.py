def func(node1,node2):
    stack1,stack2=[],[]
    while node1.next!=None:
        stack1.append(node1.val)
        node1=node1.next
    while node2.next!=None:
        stack2.append(node2.val)
        node2=node2.next
    while len(stack1)!=0 or len(stack2)!=0:
        a = stack1.pop(-1)
        b = stack2.pop(-1)
        if a==b:
            return a
        else:
            continue
    return 

