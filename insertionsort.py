"""
The list is divided into an (imaginary) sorted part and unsorted part
key is the first element of the unsorted part
The while loop compares the elements in the sorted part with the key and swaps the adjacent elements if condition in true
Due to this, the element (key) from unsorted part is inserted into the sorted part
Then, l[j+1] = key ensures that the same key is continued for this iteration as the position of key changed when it was swapped
Uncomment the print statement on line 18 to see the list after every iteration
"""
l=list(map(int, input().split()))
print("Before sorting, the given list is: ", l)
for i in range(1, len(l)):
    key=l[i]
    j=i-1
    while(j>=0 and l[j]>key):   #change > to < for descending order
        l[j+1]=l[j]
        j-=1
    l[j+1]=key
    #print("After iteration {}, list is {}".format(i, l))
print("The sorted list is: ", l)