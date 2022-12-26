# Ankit Gyandev More
# Roll number 7209
# SE Comp B

#taking Inputs
#1st matrix
n1 = int(input('Enter number  of rows in 1st matrix :',))
m1 = int(input('Enter number  of columns in 1st matrix :',))
a = []				
for i in range(n1) :
	l = list(map(int,input('enter entries of row :',).split()))
	a.append(l)

def copy(l1) :
	l = [i for i in l1]
	return l

z = copy(a)
y = copy(a)
#2nd matrix
n2 = int(input('Enter number  of rows in 2nd matrix :',))
m2 = int(input('Enter number  of columns in 2nd matrix :',))
c = []				
for i in range(n2) :
	l = list(map(int,input('enter entries of row :',).split()))
	c.append(l) 

#upper triangle matrix
f = True
for i in range(n1) :
	for j in range(m1) :
		if i>=j :
			if z[i][j] != 0 :
				f = False
if f == True :				
	print("It is upper triangular matrix")
else :
	print("It is not upper triangular matrix")

#transpose
print('Original matrix is')
print(*a)
print('Transpose of matrix is')
e = []
for i in range(m1) :
	l = []
	for j in range(n1) :
		l.append(a[j][i])
	e.append(l)		
print(*e)

# addition
add = []
for i in range(n1) :
	l = []
	for j in range(m1) :
		l.append(a[i][j] + c[i][j])
	add.append(l)
print('added matrix is : ')
print(*add)

#multiplication
if m1 == n2 :
	multiply = []
	for i in range(n1) :
		b = []
		for j in range(m2) :
			d = []
			for k in range(m1):
				d.append(a[i][k] * c[k][j])
			b.append(sum(d))
		multiply.append(b)
	print('multiplied matrix is : ')
	print(*multiply)
else :
	print('multiplication not possible')

#1st Triangle diagonal
sum = 0
for i in range(n1) :
	for j in range(m1) :
	  if(i==j) :
	     sum+= a[i][j]
print("sum of diagonal elements of 1st matrix is",sum)

#2nd Traingle Diagonal
sum = 0
for i in range(n2) :
	for j in range(m2) :
	  if(i==j) :
	     sum+= a[i][j]
print("sum of diagonal elements of 2nd matrix is",sum)

#saddle point
x = 0
y = 0
z = 0
count = 0
f = False
for i in range(n1) :
	z = c[i][0]
	for j in range(m1) :
		if c[i][j] < z :
			z = c[i][j]
			x = j
			y = i
	count = 0
	for k in range(n1) :
		if z < c[k][x] :
			break
		else :
			count+= 1
	if count == n1  :
		f = True
		break
if f == False :
	print('saddle point for 2nd matrix does not exist')
else :
	print('saddle point of 2nd matrix is : ',z)	
	
#magic square

#2nd diagonal
count = 0
h = 0
for i in range(n1):
	count += a[i][m1 - (i+1)]
if sum == count:
	f = False
	for i in range(n1):
		b = 0
		for j in range(m1) :
			b += a[i][j]
		if sum != b :
			print("1st matrix is not a magic square")
			f = False
			break
		else :
			f = True
	if f == True :
		for j in range(m1) :
			b = 0
			for i in range(n1) :
				b += a[i][j]
			if sum != b :
				print("1st matrix is not a magic square")
				h = 0
				break
			else :
				h = 1
	if h == 1 :
		print("1st matrix is a magic square")
else :
	print("1st matrix is not a magic square")