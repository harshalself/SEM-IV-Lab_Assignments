# Function to reverse a string
reverse_string() {
input="$1"
len=${#input}
reversed=""
# Loop through the characters of the string in reverse order
for (( i=len-1; i>=0; i-- )); do
reversed="${reversed}${input:i:1}"
done
echo "$reversed"
}
# Input the string to be reversed
read -p "Enter a string: " input_string
# Call the function with user input
reversed_string=$(reverse_string "$input_string")
echo "Reversed string: $reversed_string"