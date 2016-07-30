islandSet={}
n=int(raw_input())
num=0
def getRoot(x,y):
    parent=islandSet[(x,y)]
    if(parent==(x,y)):
        return (x,y)
    else:
        root=getRoot(parent[0],parent[1])
        islandSet[(x,y)]=root
        return root
def test(x,y,nx,ny):
    global num
    if islandSet.has_key((x,y)):
        root = getRoot(x,y)
        if(root!=(nx,ny)):
            islandSet[root]=(nx,ny)
            num-=1
def addPoint(x,y):
    global num
    islandSet[(x,y)]=(x,y)
    num=num+1
    if x>0:test(x-1,y,x,y)
    if(y>0):test(x,y-1,x,y)
    if(x<999):test(x+1,y,x,y)
    if(y<999):test(x,y+1,x,y)
for i in range(0,n):
    line =raw_input().split(" ")
    x=int(line[0])
    y=int(line[1])
    addPoint(x,y)
    print(num)
