# Ankit Gyandev More
# Roll number 7209
# SE Comp B 

n = int(input('Total number of students in the class :',))

# taking space separated input
marks = list(map(int,input('Enter the marks of each students out of 100 : ',).split()))

#finding average score of the class
def avrg(arr) :
    totalmarks = 0                
    for i in arr :
        if i >= 0 :
            totalmarks += i
    avg = totalmarks / n
    return avg

print("Average score of class is ",avrg(marks))

#highest and lowest score of class
def MaxMin(arr) :
    lst = list(arr)
    max = lst[0]                   
    min = lst[0]                    
    for i in lst :
        if i > max and i >= 0:
            min = i
        if i >= 0 :
            if min < 0 :
                min = i
            elif i < min :
                min = i
    return max , min
highest , lowest = MaxMin(marks)

print("Highest and Lowest score of class are",highest,lowest,"respectively")

#counting number of absent students
def absent(arr) :
    count = 0                   
    for i in arr :
        if i < 0 :
            count += 1
    return count
print("Number of absent students are",absent(marks))

# finding marks with max frequency
def frequency(arr) :
    #sorting
    for i in range(n) :
        for j in range(n-i-1) :
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    freq = []                       
    c = 0
    arr.append(1000)                     
    for i in range(len(arr) - 1) :
        if arr[i] == arr[i + 1] :
            c += 1
        else :
            freq.append(c + 1)
            c = 0
    arr.remove(1000)
    high = freq[0]                  
    for i in freq :                 
        if i > high :
            high = i
    indx = freq.index(high)      
    x = 0              
    for i in range(indx) :
        x += freq[i]
    return arr[x]
    

print("Marks with highest frequency is",frequency(marks))
    
# percentage of passed and failed students
def percent(arr) :
    #assuming passing criteria to be marks >= 40
    passing = 0                     
    for i in arr :
        if i >= 40 and i>0 :
            passing += 1
    return (passing/len(arr))*100

print("Percentage of passed students is",percent(marks))
print("Percentage of failed students is",100 -percent(marks))   #assuming absent students to be failed 

#top three scores
def top_scores(arr) :
    #sorting marks in ascending order
    n = len(arr)
    for i in range(n) :
        for j in range(n-i-1) :
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    top_score = []                 
    for i in range(len(arr) - 1,0,-1) :
        if len(top_score) > 2 :
            break
        elif arr[i] not in top_score :
            top_score.append(arr[i])       
    return top_score

print("Top scores are",*top_scores(marks))

