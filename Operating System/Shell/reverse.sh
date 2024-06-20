echo "Enter a number:"
read num
reverse_number()
{
num=$1
reverse=0
while [ $num -gt 0 ];
do
remainder=$((num % 10))
reverse=$((reverse * 10 + remainder))
num=$((num / 10))
done
echo $reverse
}
reversed_num=$(reverse_number "$num")
echo "Reversed number: $reversed_num"