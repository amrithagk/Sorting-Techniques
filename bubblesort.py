"""
Bubblesort
The idea is to take the unsorted section of the list and compare each element with the next
Swap them if condition is true
After each iteration, the size of unsorted section of list reduces
"""
#to input list from user
x=int(input('Enter number of elements in the list:'))
l=[]
for i in range (0, x):
    e=int(input("Enter number:" ))
    l.append(e)
print("The given list is", l, end="\n\n")

def bubblesort(l):
    for i in range (0, len(l)):
        for j in range(0, len(l)-1-i):
            if l[j]>l[j+1]:     #change > to < for descending order
                l[j], l[j+1]= l[j+1], l[j]
        print("After iteration", i+1, "the list is", l)
        #print("Sorted section: ", l[len(l)-i-1:])  #uncomment this line to see the sorted portion
    print('\nThe sorted list is', l)
bubblesort(l)
