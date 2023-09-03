def GeraSub (ns, t,cp,ci):
    contp = cp
    conti = ci
    for i in range(t,n):
        if V[i]%2 == 0:
            contp = contp+1
        else:
            conti = conti+1
        S[ns] = V[i]
        if conti==contp:
            for j in range(0,ns+1):
                print(S[j],end =' ')
            print( )
        if (i<n):
            GeraSub (ns+1, i + 1,contp,conti)
        if V[i]%2 == 0:
            contp = contp-1
        else:
            conti = conti-1


n = 4
V = [-1]*n
for i in range(0,n):
     V[i] = int(input("Elemento: "))
S = [0]*n
GeraSub (0, 0,0,0)
