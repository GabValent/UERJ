#GABRIEL DE OLIVEIRA VALENTE ALGORITMO TROCO BOTTOM-UP

def moedas(vet,m):
    n = len(vet)
    dp = [100]*(m+1)
    dp[0] = 0
    for i in range(1,m+1):
        for j in range(0,n):
            if(vet[j] <= i):
                dp[i] = min(dp[i], dp[i-vet[j]]+1)
    return dp[m]



vet = [50,25,10,5,1]
a = int(input("Digite o troco que deseja saber o minimo de moedas a ser dado: "))

minimo = moedas(vet,a)
print("O minimo de moedas para o troco e de:",minimo,"moeda(s)")
