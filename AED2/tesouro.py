#para j = 0,...,n faça W[j,0] = 1;
#para w = 1,...,K faça W[0,w] = 0;
#para j = 1,...,n faça
#para w = 1,...,K faça
#W[j,w] = W[j-1,w] ou W[j-1,w-x[j]];
#para w = K, ..., 0 faça
#se W[n,w] == 1 então
#Retornar w.
def maxsoma(ns,t,soma):
    i = t
    while (i<=len(peso)-1 and soma+peso[i]<=s):
        g[ns] = i+1
        soma = soma + peso[i]
        if soma==s:
             vet = []
             a = 0
             while g[a]!=-1:
                 vet.append(g[a])
                 a = a+1
             print(vet)
             #ele mostra alguns vetores a mais, tentei solucionar porem sem sucesso
        else:
            maxsoma(ns+1,t+1,soma)
        soma = soma - peso[i]
        i = i+1

        
def pack(k,n):
    for j in range(0,n):
        memo[j][0] = 1
    for w in range(1,k):
        memo[0][w] = 0
    for j in range(1,n):
        for w in range(1,k):
            memo[j][w] = max(memo[j-1][w],memo[j-1][w-peso[j]])
                             
    for w in range(k-1,0,-1):
        if memo[n-1][w] == 1:
            return w+1

peso = [3,10,4,6,8]
k = 19
vet = [0]
memo = []
g = [-1]*len(peso)
for c in range(0,len(peso)):
    l = []
    for j in range(0,k):
        l.append(-1)
    memo.append(l)
s = pack(k,len(peso))
soma = 0
peso.sort()
print(peso)
maxsoma(0,0,soma)
