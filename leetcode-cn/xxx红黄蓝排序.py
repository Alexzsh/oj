li=[2, 2, 2, 1, 1, 1, 0, 0, 0]
def getcolor(index):
    return li[index]
def swap(l,r):
    li[l],li[r]=li[r],li[l]
def func():
    r,g,b=0,1,2
    index=0

    while index<9:
        x=getcolor(index)
        y = index%3
        if x==y:
            index+=1
        else:
            if x==0:
                swap(r,index)
                r+=3
            elif x==1:
                swap(g,index)
                g+=3
            elif x==2:
                swap(b,index)
                b+=3

        # while getcolor(li, index) != list(color.keys())[index % 3]:
        #     color[getcolor(li, index)] += 3
        #     swap(li,index,color[getcolor(li,index)])
            
        # index+=1
    print(li)
if __name__ == '__main__':
    color = {'r': 0, 'g': 1, 'b': 2}
    print(list(color.keys()))
    func()
