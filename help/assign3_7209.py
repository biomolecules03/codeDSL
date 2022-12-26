# Ankit Gyandev More
# Roll number 7209
# SE Comp B 

n = int(input('Enter number of books : ',))

# taking space separated input
name = input('Enter name of books : ',).split()
cost = list(map(int,input('Enter cost of books : ',).split()))

#deleting duplicate entries
def duplicate(x) :	
	n1 = []
	for i in x :
		if i not in n1 :
			n1.append(i)
	return n1
print('List of books after deleting duplicate entries : ',duplicate(name))

#arrangig books in ascending order of their cost
def ascending(x) :
	n1 = []
	c1 = []
	for i in range(n) :
		if x[i] not in n1 :
			n1.append(x[i])
			c1.append(cost[i])
	c2 = list(c1)
	n2 = []
	while len(c1)>0 :
		a = c1.index(min(c1)) 
		n2.append(n1[a])
		c1.pop(a)
		n1.pop(a)
		if ValueError :
			continue
	return n2,c2
a,b = ascending(name)
print('Books in ascending order of their costs are : ',a)

#number of books with cost more than 500
def numb(x) :
	count = 0
	for i in x :
		if i > 500 :
			count+=1
	return count
print('number of books with cost more than 500 : ',numb(b))

#books having cost less than 500
def books(x) :
	l = []
	for i in range(n) :
		if x[i] < 500 :
			l.append(name[i])
	return l
print('Books having cost less than 500 : ',duplicate(books(cost)))
	

