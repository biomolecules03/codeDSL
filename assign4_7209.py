# Ankit Gyandev More
# Roll number 7209
# SE Comp B
for _ in range(int(input())) :
	a = int(input('Enter number of students in first class : ',))
	b = int(input('Enter number of students in second class : ',))
	#taking Input
	print('Enter for students of first class')
	comp_A = []				
	for i in range(a) :
		l = list(map(int,input('enter prn,date,month : ',).split()))
		comp_A.append(l)
	print('Enter for students of second class')
	comp_B = []				
	for i in range(b) :
		l = list(map(int,input('enter prn,date,month : ',).split()))
		comp_B.append(l)
	c = 0
	d = 0
	List_SE_Comp_DOB = []
	#Comparing and arranging
	while c < a and d < b :
		if comp_A[c][2] < comp_B[d][2] :
			List_SE_Comp_DOB.append(comp_A[c])
			c+=1
		elif comp_A[c][2] > comp_B[d][2] :
			List_SE_Comp_DOB.append(comp_B[d])
			d+=1
		else :
			if comp_A[c][1] < comp_B[d][1] :
				List_SE_Comp_DOB.append(comp_A[c])
				c+=1
			elif comp_A[c][1] > comp_B[d][1] :
				List_SE_Comp_DOB.append(comp_B[d])
				d+=1
			else :
				List_SE_Comp_DOB.append(comp_A[c])
				List_SE_Comp_DOB.append(comp_B[d])
				c+=1
				d+=1
	while c < a :
		List_SE_Comp_DOB.append(comp_A[c])
		c+=1
	while d < b :
		List_SE_Comp_DOB.append(comp_B[d])
		d +=1
    #Printing merged  list 
	print('sorted Date of Birth of SE Computer students : ',List_SE_Comp_DOB)


		
		

