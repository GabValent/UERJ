def GeraSub (ns, t,mai,men):
    maior = mai
    menor = men
    for i in range(t,n):
        if V[i]>=maior:
            maior = V[i]
        if V[i]<=menor:
            menor = V[i]
        S[ns] = V[i]
        dif = maior-menor
        if ns>=1 and dif<=100:
            for j in range(0,ns+1):
                print(S[j],end =' ')
            print( )
            #problema na saída pois ele sempre considera o 100 como menor
        if (i<n):
            GeraSub (ns+1, i + 1,maior,menor)
        if V[i]>maior:
            maior = mai
        if V[i]<=menor:
            menor = V[i]
            #teria que trocar por outra variavel que indica para trocar o menor(ja testei ns,t,i e nenhuma ainda deu resultado)


n = 4
V = [-1]*n
S = [-1]*n
for i in range(0,n):
     V[i] = int(input("Elemento: "))
GeraSub (0, 0,-10*3,10*3)
