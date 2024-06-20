#Name:Tanmay Tambat
#class:S.Y.B.Tech
#Roll no.:70
#Assignment :2
#Problem statement:Write a shell script to find factorial of a given
number.
echo "While loop:"
echo "Enter a number"
read num
fact=1
while [ $num -gt 1 ]
do
fact=$((fact * num))
num=$((num - 1))
done
echo "Factorial:" $fact
echo "For loop:"
echo "Enter a number"
read num1
fact1=1
for((i=1; i <= $num1; i++))
do
fact1=$((fact1 * i))
done
echo "Factorial:" $fact1
#kkw@kkw-HP-280-G2-MT-Legacy:~/Desktop/SY_A_70$ chmod +x Assignment2.sh
#kkw@kkw-HP-280-G2-MT-Legacy:~/Desktop/SY_A_70$ ./Assignment2.sh
#While loop:
#Enter a number
#5
#Factorial: 120
#For loop:
#Enter a number
#4
#Factorial: 24