#GABRIEL DE OLIVEIRA VALENTE ALGORITMO TROCO TOP-DOWN

def troco(x,memo):
    if x==0:
        return 0
    if(memo[x-1]!=-1):
        return memo[x-1]
    
    memo[x-1] = 10**10
    for i in (vet):
        if i>x:
            continue
        else:
            memo[x-1] = min(memo[x-1],1+troco(x-i,memo))
                    
    return memo[x-1]


vet = [50,25,10,5,1]
a = 15
b = [-1]*a

minimo = troco(a,b)
print("O minimo de moedas para o troco e de:",minimo,"moeda(s)")
