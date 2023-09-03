def Blocos (p, v):
    global cpre 
    cpre = cpre+1
    pre[v] = cpre
    low[v] = cpre
    for i in range(0,n):
        for w in range(0,n):
            if matriz[i][w] == 1:
                if  marca[i][w] == 0:
                    pilha.append([i,w])
                    marca[i][w] = 1
                if pre[w] == 0:
                    Blocos(v, w)
                    if pre[v] <= low[w]:
                        while pilha.del(0) != [w,v]:
                               print(pilha.del(0))
                    low[v] = min (low[v], low[w])
                elif w != p:
                    low[v] = min (low[v], pre[w])

cpre = 0



n=6
pilha = []
cpre = 0
pre = [0]*n
low = [0]*n

marca = [ [0,0,0,0,0,0], [0,0,0,0,0,0], [0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,0,0,0,0]]
    
matriz = [ [0,1,0,0,1,1], [1,0,1,1,0,0], [0,1,0,1,0,0],[0,1,1,0,0,0],[1,0,0,0,0,1],[1,0,0,0,1,0]]


Blocos(0,0)

