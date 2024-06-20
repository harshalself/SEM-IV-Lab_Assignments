#Name:Tanmay Tambat
#class:S.Y.B.Tech
#Roll no.:70
#Assignment 1:
#Problem statement:Write a shell script for implementation of control flow
statements.
echo "Enter a: "
read a
echo "Enter b: "
read b
if [ $a == $b ]
then
echo "a is equal to b"
elif [ $a -gt $b ]
then
echo "a is greater than b"
else
echo "a is less than b"
fi
#kkw@kkw-HP-280-G2-MT-Legacy:~/Desktop/SY_A_70$ chmod +x Assignment1.sh
#kkw@kkw-HP-280-G2-MT-Legacy:~/Desktop/SY_A_70$ ./Assignment1.sh
#Enter a:
#4
#Enter b:
#6
#a is less than b