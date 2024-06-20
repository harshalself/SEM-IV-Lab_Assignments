# Define an array
my_array=("apple" "banana" "cherry" "date" "fig")
# Get the length of the array
array_length=${#my_array[@]}
# Initialize a counter variable
counter=0
# Loop through the array elements using a while loop
while [ $counter -lt $array_length ]; do
# Print the current element
echo "${my_array[$counter]}"
# Increment the counter
((counter++))
done