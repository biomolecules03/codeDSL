# Ankit Gyandev More
# Roll number 7209
# SE Comp B

#taking input
n=int(input("total no. of players:"))
a=int(input("no. of players playing cricket:"))
b=int(input("no. of players playing badminton:"))
c=int(input("no. of players playing football:"))
a1=[]
b1=[]
c1=[]
for i in range(a):
   x=int(input("enter  cricket player's roll no.: "))
   a1.append(x)
for i in range(b):
   y=int(input("enter badminton player's roll no.: "))
   b1.append(y)
for i in range(c):
   z=int(input("enter football player's roll no.: "))
   c1.append(z)

#List of students who play both cricket and badminton
ab=[]
x=0
for i in range(a):
   for j in range(b):
      if(a1[i]==b1[j]):
        ab.append(a1[i])
        x=x+1
print("Players playing both cricket and badminton:")
print(ab)

#List of students who play either cricket or badminton but not both
aob=[]
y=0
z=0
for i in range(a):
   y=0
   for j in range(x):
      if(ab[j]==a1[i]):
         break
      else:
         y=y+1   
      if(y==x):
         aob.append(a1[i])
         z=z+1
for i in range(b):
    y=0
    for j in range(x):
       if(b1[i]==ab[j]):
          break
       else:
          y=y+1
       if(y==x):
          aob.append(b1[i])
          z=z+1
print("Players playing cricket or badminton but not both:")
print(aob)

#Number of students who play neither cricket nor badminton
r=0
for i in range(b):
   for j in range(c):
      if(b1[i]==c1[j]):
        r=r+1      
t=0
q=[]
for i in range(a):
   for j in range(c):
      if(a1[i]==c1[j]):
        t=t+1    
z=0  
for i in range(a):
   for j in range(b):
      for k in range(c):
        if(a1[i]==b1[j] and a1[i]==c1[k]):
             z=z+1
             q.append(a1[i])     
print("players playing neither cricket nor badminton:",(c-r-t+z))

#Number of students who play cricket and football but not badminton
y=0
for i in a1:
   if i in c1:  
       if i not in b1:
         y=y+1
print("players playing both cricket and football but not badminton:",y)  

#List of students who play at least one game
l=[]
x=0
for i in range(a):
   if(l.count(a1[i])==0):
     l.append(a1[i])
     x=x+1
for i in range(b):
    if(l.count(b1[i])==0):
      l.append(b1[i])
      x=x+1
for i in range(c):
    if(l.count(c1[i])==0):
      l.append(c1[i])  
      x=x+1
print("players playing at least playing one game:")
print(l)

#Number of students who do not play any game
print("not playing any game:",n-len(l))

# List of students who play all three games
if(len(q)>0):
   print("Players play all:")
   print(q)
else:
    print("No one played all")
    