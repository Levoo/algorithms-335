
a  = [12, 44, 13, 88, 23, 94, 11, 39, 20, 16]
ht = [[], [], [], [], [], [], [], [], [], [], []] # linked list inside hast atble 
for num in a:
    tmp = ((2 * num) + 5) % 11
    if(len(ht[tmp]) > 0):
        print("\tCollision at position " + str(tmp+1) + " adding number " + str(num) + " to this positions linked list")
        ht[tmp].append(num)
    else:
        print("For number " + str(num) + " put in position " + str(tmp+1))
        ht[tmp].append(num)
print(" Pos   items")
count = 1
for item in ht:
    print("| " + str(count) + " | ",end="")
    if len(item) > 0:
        for num in item:
            print (str(num) + " ", end="")
        print("")
    else:
        print("empty...")
    count += 1

