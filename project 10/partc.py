
a  = [12, 44, 13, 88, 23, 94, 11, 39, 20, 16]
ht1 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] # only add one to list
ht2 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] 
rapAround = True
count = 1
tLoc = 0
for num in a:
    loc = ((2 * num) + 5) % 11
    if(ht1[loc] != 0):
        print("---\n  Collision for num " + str(num) + " at pos " + str(loc+1) + ":")
        print("  checking second hash table")
        if(ht2[loc] != 0):
            while rapAround: # keep checking until we check all of em
                tLoc = ((2 * (num + count)**2) + 5) % 11
                print("\tChecking position " + str(tLoc+1))
                if count > 11:
                    print("No open positions in hash table, all is full...")
                    rapAround = False
                if ht2[tLoc] == 0:
                    print("\tPosition " + str(tLoc+1) + " has been chosen for num " + str(num))
                    ht2[tLoc] = num 
                    rapAround = False
                count += 1
            count = 1           # reset both values
            rapAround = True
            print("---")
        else:
            print("  For number " + str(num) + " put in position " + str(loc+1) + " in HT 2.")
            ht2[loc] = num
    else:
        print("For number " + str(num) + " put in position " + str(loc+1) + " in HT 1.")
        ht1[loc] = num

print(" Pos   HT1  HT2")
for item1, item2 in zip(ht1, ht2): # zip creates a list of tuples can be bad memoery wise if list a and b are large 
    print("| " + str(count) + " | ",end="")
    if item1 != 0:
       print(" " + str(item1), end="")
    if item1 == 0:
        print(" - ", end="")
    if item2 != 0:
       print("   " + str(item2))
    if item2 == 0:
        print("   - ")
    count += 1
