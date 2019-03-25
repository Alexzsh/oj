seq = list(map(int,'101222001'))
def getColor(i):
    return seq[i]
def swap(i,j):
    seq[i],seq[j]=seq[j],seq[i]
def func():
    index = 0
    li=['R','G','B']
    color_index=[-3,-2,-1]
    while index<len(seq):
        while getColor(index)!=index%3:
            color_index[getColor(index)] += 3
            swap(index, color_index[getColor(index)])
        if index>color_index[index%3]:
            color_index[index%3]+=3
        index+=1
    print(seq)
if __name__ == '__main__':
    func()
    
