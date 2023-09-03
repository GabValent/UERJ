def GeraSub (ns, t,soma):
    for i in range(t,n):
        S[ns] = V[i]
        soma = soma+V[i]
        if (soma%2)==0:
            print(S)
        if (i<n):
            GeraSub (ns+1, i + 1,soma)
        soma = soma-V[i]


n = 5
V = [-1]*n
S = [-1]*n
for i in range(0,n):
     V[i] = int(input("Elemento: "))
GeraSub (0, 0,0)
