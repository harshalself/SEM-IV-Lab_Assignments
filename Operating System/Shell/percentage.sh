# Function to calculate percentage
calculate_percentage() {
total_marks=$1
max_marks=$2
percentage=$(( (total_marks * 100) / max_marks ))
echo $percentage
}
# Function to calculate grade based on percentage
calculate_grade() {
percentage=$1
# Switch case to assign grade based on percentage
case $percentage in
90[0-9]*)
grade="A+";;
8[0-9]*)
grade="A";;
7[0-9]*)
grade="B+";;
6[0-9]*)
grade="B";;
5[0-9]*)
grade="C";;
4[0-9]*)
grade="D";;
[0-3][0-9]*)
grade="Fail";;
*)
grade="Invalid";;
esac
echo $grade
}
# Main function
main() {
read -p "Enter the number of students: " num_students
read -p "Enter the maximum marks for each subject: " max_marks
for ((i=1; i<=$num_students; i++)); do
echo "Enter marks for student $i:"
total_marks=0
for ((j=1; j<=5; j++)); do
read -p "Enter marks for subject $j: " marks
total_marks=$((total_marks + marks))
done
percentage=$(calculate_percentage $total_marks $((max_marks * 5)))
echo "Percentage for student $i: $percentage%"
# Calculate grade using the calculate_grade function
grade=$(calculate_grade $percentage)
echo "Grade for student $i: $grade"
echo
done
}
# Call the main function
main