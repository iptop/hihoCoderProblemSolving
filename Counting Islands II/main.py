islandSet={} #全部集合

n=int(raw_input())

def countIsland(): #计算全部集合总共有几个根节点
    RootSet={}
    for k in islandSet:
        root= getRoot(k[0],k[1])
        RootSet[root]=1
    print(len(RootSet) )

def getRoot(x,y): #获得集合的根节点
    parent=islandSet[(x,y)]
    if(parent==(x,y)):
        return (x,y)
    else:
        return getRoot(parent[0],parent[1])


def test(x,y,nx,ny): #判断是否有相邻的集合
    if islandSet.has_key((x,y)):
        root = getRoot(x,y)
        islandSet[root]=(nx,ny)


def addPoint(x,y): #添加集合
    islandSet[(x,y)]=(x,y)
    if x>0:test(x-1,y,x,y)
    if(y>0):test(x,y-1,x,y)
    if(x<999):test(x+1,y,x,y)
    if(y<999):test(x,y+1,x,y)

for i in range(0,n):
    line =raw_input().split(" ")
    x=int(line[0])
    y=int(line[1])
    addPoint(x,y)
    countIsland()



