#GABRIEL DE OLIVEIRA VALENTE

def torneio(m, t):
    if m==1:
        t[0][0] = 1
    else:
        p = m//2
        torneio(p,t)
        for i in range(0,p):
            for j in range(0,p):
                t[i+p][j] = t[i][j] + p
                t[i] [j+p] = m-((j-i+m)%p)
                mod = m-((j-i+m)%p)
                t[mod-1][j+p] = i+1


n = 8
a = []
for c in range(0,n):
    l = []
    for j in range(0,n):
        l.append(0)
    a.append(l)
    
torneio(n,a)

for i in range(0,n):
    for j in range(0,n):
        print(f'{a[i][j]:^2}' , end=' ')
    print()
    
            
