#Selection sort
"""
The idea is to mark the 1st element and compare it with the next element
If condition is true, change the position of marker to the next element
Compare the next two elements
    until the desired(greatest or smallest) element is obtained
If the position changed from starting element,
    swap the current position and initial position of that iteration
"""
l=[6, 5, 3, 7, 2, 8, 4]
print("Before sorting, list is ", l)
for i in range(len(l)-1):
    pos=i
    for j in range(i+1, len(l)):
        if(l[pos]>l[j]):
            pos=j
    if pos!=i:
        l[pos], l[i]=l[i], l[pos]
    print("After iteration ", i+1, " list is ", l, sep="");
print("After sorting in ascending order, the list is ", l)
