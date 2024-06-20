import mysql.connector

def menu():
    print("MENU")
    print("1.Create table")
    print("2.Insert Rows")
    print("3.Display Items")
    print("4. Search For a Item")
    print("5. Exit from the program")
def rchoice():
    c=int(input("Enter Your Choice"))
    return c
def create_connection():
    #created mydemo database in mysql
    con = mysql.connector.connect(host="localhost", user="root",password="system",database="mydemo")
    cur = con.cursor()
    return con,cur
def create_table():
    con, cur= create_connection()
    strSQL = "create table student(""roll int(5) primary key,""name varchar(10));"
    try:
        cur.execute(strSQL)
    except:
        pass
    con.close()

def insert_row():
    roll = int(input("Enter the roll no"))
    name= input("Enetr the item name")
    con, cur= create_connection()
    strSQL= "insert into student values(""%s,%s);"
    v=(roll,name)
    cur.execute(strSQL,v)
    con.commit()
    con.close()
def show_table():
    con, cur= create_connection()
    strSQL = "select * from student;"
    cur.execute(strSQL)
    r=cur.fetchall()
    for i in r:
        print(i)
    con.close()
def search():
    name= input("Enter the item name")
    con, cur= create_connection()
    strSQL = "select * from student where name=" "%s;"
    v=(name,)
    cur.execute(strSQL,v)
    r=cur.fetchall()
    if r == []:
        print (name,"Not Found")
    else:
        print(name, "Found")
        print("Details are given below")
        print(r)
    con.close()
while True:
    menu()
    c= rchoice()
    if c ==1:
        create_table()
    elif c==2:
        insert_row()
    elif c==3:
        show_table()
    elif c==4:
        search()
    elif c==5:
        break
    else:
        print("Wrong Choice")
        
    
