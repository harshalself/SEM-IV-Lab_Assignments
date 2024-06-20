import pymongo

client = pymongo.MongoClient("mongodb://localhost:27017/")
db = client["pract"]
collection = db["student"]
def insert_student():
    rollno = int(input("Enter Roll Number: "))
    name = input("Enter Name: ")
    address = input("Enter Address: ")
    contact_no = input("Enter Contact Number: ")
    department = input("Enter Department: ")
    student = {"rollno": rollno, "name": name, "address": address, "contact_no": contact_no, "department": department}
    collection.insert_one(student)
    print("Student details inserted successfully.")

def update_address():
    name = input("Enter student's name whose address you want to update: ")
    new_address = input("Enter the new address: ")
    collection.update_one({"name": name}, {"$set": {"address": new_address}})
    print("Address updated successfully.")

def display_student():
    rollno = int(input("Enter Roll Number to display details: "))
    student = collection.find_one({"rollno": rollno})
    if student:
        print("Student Details:")
        print("Roll No:", student["rollno"])
        print("Name:", student["name"])
        print("Address:", student["address"])
        print("Contact No:", student["contact_no"])
        print("Department:", student["department"])
    else:
        print("Student not found.")
def delete_student():
  rollno = int(input("Enter Roll Number to delete student's record: "))
  result = collection.delete_one({"rollno": rollno})
  if result.deleted_count:
    print("Student record deleted successfully.")
  else:
    print("Student not found.")
  
while True:
    print("\nMenu:")
    print("1. Insert Student")
    print("2. Update Address")
    print("3. Display Student Information")
    print("4. Delete Student Record")
    print("5. Exit")
    choice = input("Enter your choice: ")
    if choice == "1":
       insert_student()
    elif choice == "2":
        update_address()
    elif choice == "3":
        display_student()
    elif choice == "4":
        delete_student()
    elif choice == "5":
        print("Exiting program...")
        break
    else:
        print("Invalid choice. Please enter a..")