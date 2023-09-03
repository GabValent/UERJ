def maxsoma(n):
    t = len(ouro)
    maxsoma = 0
    for i in range(0,t):
        g = []
        if c-profun[i]>=0:
            num = c-profun[i]
            g.append(i+1)
            soma = ouro[i]
        for j in range(i,t):
            if i!=j:
                if num-profun[j]>=0:
                    num = num-profun[j]
                    g.append(j+1)
                    soma = soma+ouro[j]
        if soma>maxsoma:
            maxsoma = soma
            maxvet = g
    print("Podemos levar ate",len(maxvet),"tesouros e os tesouros que podemos levar são",maxvet,"que nos resulta uma quantidade",n,"de ouro")


def knapSack(n, c):
     for i in range(0,n + 1):
         for j in range(0,c + 1):
             if i == 0  or  j == 0:
                 K[i][j] = 0
             elif profun[i-1] <= j:
                 K[i][j] = max(K[i-1][j],ouro[i-1]+ K[i-1][j-profun[i-1]])
             else:
                 K[i][j] = K[i-1][j]
     maxsoma(K[n][c])

ouro = [60,100,120]
profun = [5,10,15]
c = 25
n = len(ouro)
K = []
for i in range(0,n+1):
    l = []
    for j in range(0,c+1):
        l.append(-1)
    K.append(l)
    
knapSack(n, c)
