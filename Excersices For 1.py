#exercises bucles-for
#1) Calculate the sum of the squares of the n numbers wich are positives

n = int(input("enter the number wich define de n numbers: "))
f = 1
summ =0 
if n > 0:
    for i in range(f,n+1): #defining de range of numbers
        print(i,i*i) #print the square of the bucle of the numbers
        summ = summ+(i*i)

print("The sum of the squares: ",summ)
