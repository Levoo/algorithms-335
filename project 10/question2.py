c, r = 19, 7
nap = [[0 for x in range(c)] for y in range(r)]

vwi = [ [7, 1, 1],  # value, weight, index< not used :( >
        [14, 3, 2], 
        [12, 4, 3], 
        [8, 5, 4], 
        [9, 6, 5],
        [10, 6, 6], 
        [11, 7, 7] ]

for i in range(7):
    for j in range(19):
        if j < vwi[i][1]:
            nap[i][j] = nap[i - 1][j]
        else:
            a = nap[i - 1][j]
            b = nap[i-1][j-vwi[i][1]] + vwi[i][0]
            nap[i][j] = max(a, b)

for row in nap:
    for num in row:
        print (str(num) + " | ",   end="")
    print("") 
