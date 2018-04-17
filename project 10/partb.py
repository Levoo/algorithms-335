a  = [12, 44, 13, 88, 23, 94, 11, 39, 20, 16]
ht = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] # only add one to list 
rapAround = True
count = 1
tLoc = 0
for num in a:
    loc = ((2 * num) + 5) % 11
    if(ht[loc] != 0):
        print("---\n  Collision for num " + str(num) + " at pos " + str(loc) + ":")
        while rapAround: # keep checking until we check all of em
            tLoc = ((2 * (num + count)) + 5) % 11
            print("\tChecking position " + str(tLoc+1))
            if count > 11:
                print("No open positions in hash table, all is full...")
                rapAround = False
            if ht[tLoc] == 0:
                print("\tPosition " + str(tLoc+1) + " has been chosen for num " + str(num))
                ht[tLoc] = num 
                rapAround = False
            count += 1
        count = 1           # reset both values
        rapAround = True
        print("---")
    else:
        print("For number " + str(num) + " put in position " + str(loc+1))
        ht[loc] = num

print(" Pos   items")
for item in ht:
    print("| " + str(count) + " | ",end="")
    if item != 0:
       print(" " + str(item))
    else:
        print("empty...")
    count += 1
