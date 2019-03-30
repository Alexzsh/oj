def func(root):
    '''
    root:ListNode
    '''
    if root==None or root.next==None:
        return root
    odd = root
    even = root.next 
    first_even = even # 用于记录第一个偶数点位置 
    # 先串奇数链和偶数链
    while even and even.next:
        odd.next = odd.next.next
        if odd.next:
            odd = odd.next
        even.next = even.next.next
        even = even.next	
    # 最后把奇偶串起来
    odd.next = first_even
    return root
if __name__ == '__main__':
    func()
    
