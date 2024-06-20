# Function to generate Fibonacci series
fibonacci() {
n=$1
a=0
b=1
# Check if n is less than or equal to 0
if [ $n -le 0 ]; then
echo "Invalid input!"
return
fi
echo "Fibonacci series up to $n terms:"
echo -n "$a "
# Generate Fibonacci series up to n terms
for ((i = 1; i < n; i++)); do
echo -n "$b "
fn=$((a + b))
a=$b
b=$fn
done
echo "" # Print newline
}
# Input the number of terms
read -p "Enter the number of terms: " num_terms
# Call the function with user input
fibonacci $num_terms