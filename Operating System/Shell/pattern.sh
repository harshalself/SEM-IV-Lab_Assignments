# Program to print a square pattern
print_square() {
size=$1
for ((i=1; i<=size; i++)); do
for ((j=1; j<=size; j++)); do
echo -n "* "
done
echo
done
}
echo "Enter the size of the square pattern:"
read size
print_square "$size"
//OUTPUT
if input is given 5
* * * * *
* * * * *
* * * * *
* * * * *
* * * * *
# Program to print a triangle pattern
print_triangle() {
size=$1
for ((i=1; i<=size; i++)); do
for ((j=1; j<=i; j++)); do
echo -n "* "
done
echo
done
}
echo "Enter the size of the triangle pattern:"
read size
print_triangle "$size"
//OUTPUT
if input is given 5
*
* *
* * *
* * * *
* * * * *
# Program to print an upside-down triangle pattern
print_upside_down_triangle() {
size=$1
for ((i=size; i>=1; i--)); do
for ((j=1; j<=i; j++)); do
echo -n "* "
done
echo
done
}
echo "Enter the size of the upside-down triangle pattern:"
read size
print_upside_down_triangle "$size"
//OUTPUT
if input is given 5
* * * * *
* * * *
* * *
* *
*
# Program to print an upside-down triangle pattern(number)
print_upside_down_number_triangle() {
size=$1
for ((i=size; i>=1; i--)); do
for ((j=1; j<=size-i+1; j++)); do
echo -n "$j "
done
echo
done
}
echo "Enter the size of the upside-down number triangle pattern:"
read size
print_upside_down_number_triangle "$size"
//OUTPUT
if input is given 5
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
# Program to print a triangle pattern(number)
print_triangle() {
size=$1
for ((i=1; i<=size; i++)); do
for ((j=1; j<=i; j++)); do
echo -n "$j "
done
echo
done
}
echo "Enter the size of the triangle pattern:"
read size
print_triangle "$size"
//OUTPUT
if input is given 5
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5