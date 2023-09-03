def GeraSub (ns, t):
    for i in range(t,n):
        S[ns] = V[i]
        if ns == t:
            for j in range(0,ns+1):
                print(S[j],end =' ')
            print( )
        if (i<n):
            GeraSub (ns+1, i + 1)


n = 4
V = [-1]*n
S = [-1]*n
for i in range(0,n):
     V[i] = int(input("Elemento: "))
GeraSub (0, 0)
