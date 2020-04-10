def longestCommonSubsequence(X, Y, m, n):
    L = [[0 for x in range(m+1)] for y in range(n+1)] 
    C = [[0 for x in range(m+1)] for y in range(n+1)]
    print(len(L))
    for i in range(m+1):
        for j in range(n+1):
            if(i==0 or j==0):
                L[i][j] = 0
            elif (X[i-1] == Y[j-1]):
                L[i][j] = L[i-1][j-1] + 1
                C[i][j] = "D" 
            elif(L[i-1][j] >= L[i][j-1]):
                L[i][j] = L[i-1][j]
                C[i][j] = "U"
            else:
                L[i][j] = L[i][j-1]
                C[i][j] = "L"
    i = m
    j = n
    sub = []
    while i!=0 and j!=0:
        if(C[i][j] == 'U'):
            i = i-1
        elif(C[i][j] == 'L'):
            j = j-1
        else:
            sub.append(X[i])
            i = i-1
            j = j-1

    for i in range(m+1):
        for j in range(n+1):
            if i==0 or j==0:
                print(L[i][j],end="    ")
            else:
                print(L[i][j],C[i][j],end ="  ")
        print()
    
    sub.reverse()
    print(''.join(sub))

X = "abaaba"
Y = "babbab"
m = len(X)
n = len(Y)
longestCommonSubsequence(X, Y, m, n)