// Assignment No. 2 
/* Problem Statement : Department maintains a student information. The 
file contains roll number, name, 
division and address. Allow user to add, delete information of student. 
Display 
information of particular student. If record of student does not exist an 
appropriate 
message is displayed. If it is, then the system displays the student 
details. Use sequential file to main the data. 
*/ 
#include<iostream> 
#include<fstream> 
#include<cstdio> 

using namespace std; 

class student 
{
public: 

int rollno; 
char name[50]; 
char add[50]; 
char div[5]; 


void setData() 
{
cout<<"\n----------------------------------------"; 
cout<<"\nEnter Roll no: "; 
cin>>rollno; 
cout<<"Enter Name: "; 
cin>>name; 
cout<<"Address of student: "; 
cin>>add; 
cout<<"Division of student: "; 
cin>>div; 
}

void showData() 
{
cout<<"\n----------------------------------------"; 
cout<<"\n Roll number of student: "<<rollno; 
cout<<"\n Name of the student: "<<name; 
cout<<"\n Address of student: "<<add; 
cout<<"\n Division of student: "<<div; 
}

int retrollno() 
{
return rollno; 
}
}; 
 
void create() 
{
ofstream outfile; 
outfile.open("StudentData", ios::binary | ios::app); 

student obj; 
obj.setData(); 
outfile.write((char*)&obj, sizeof(obj)); 
outfile.close(); 
}

void display() 
{
ifstream infile; 
infile.open("StudentData", ios::binary); 

student obj; 

while(infile.read((char*)&obj, sizeof(obj))) 
{
obj.showData(); 
}
infile.close(); 
}

void search(int n) 
{
bool flag=false; ifstream infile; 
infile.open("StudentData", ios::binary); 

student obj; 


while (infile.read((char*)&obj, sizeof(obj))) 
{
if(obj.rollno==n) 
{
flag=true; 
obj.showData(); 
break; 
}
if(flag==false) 
{
cout<<"Record for roll no. is not found in the file."; 
}
}
}

void deleter(int n) 
{
student obj; 
 
ifstream infile; 
infile.open("StudentData", ios::binary); 

ofstream outfile; 
outfile.open("StudentNewData", ios::out | ios::binary); 

while(infile.read((char*)&obj, sizeof(obj))) 
{
if(obj.retrollno() != n) 
{
outfile.write((char*)&obj, sizeof(obj)); 
}
}
infile.close(); 
outfile.close(); 
remove("StudentData"); 
rename("StudentNewData","StudentData"); 
}

int main() 
{
int ch; 
do 
{
cout<<"\n.............File Operations..............\n 1.Add 
Record. \n 2.Display Record. \n 3.Search a particular Record. \n 4.Delete 
particular Record. \n 5.Exit"; 

cout<<"\n Enter your choice: "; 
cin>>ch; 
switch(ch) 
{
case 1: 
cout<<"Enter total no. of records you want to store in a file: 
"; 
int n; 
cin>>n; 
for(int i=0; i<n; i++) 
{
create(); 
}
break; 
case 2: 
cout<<"\n List of records: "; 
display(); 
break; 
case 3: 
cout<<"Enter student roll no. whose record you want search: "; 
int s; 
cin>>s; 
search(s); 
break; 
case 4: 
 
cout<<"Enter student roll no. whose record you want delete: "; 
int t; 
cin>>t; 
deleter(t); 
cout<<"Record Deleted Successfully!!"; 
break; 
case 5: 
return 0; 
}
}while(ch!=6); 
}


Output : 
.............File Operations.............. 
1. Add Record. 
2. Display Record. 
3. Search a particular Record. 4. Delete particular Record. 
5. Exit 
Enter your choice: 1 
Enter total no. of records you want to store in a file: 3 

---------------------------------------- 
Enter Roll no: 06 
Enter Name: Kaustubh 
Address of student: Pune 
Division of student: B 

---------------------------------------- 
Enter Roll no: 11 
Enter Name: Avishkar 
Address of student: Nashik 
Division of student: C 

---------------------------------------- 
Enter Roll no: 26 
Enter Name: Prathmesh 
Address of student: Sangli 
Division of student: D 

.............File Operations.............. 
1. Add Record. 
2. Display Record. 
3. Search a particular Record. 4. Delete particular Record. 
5. Exit 
Enter your choice: 2 

List of records: 
---------------------------------------- 
Roll number of student: 06 
Name of the student: Kaustubh 
Address of student: Pune 
 
Division of student: B 
---------------------------------------- 
Roll number of student: 11 
Name of the student: Avishkar 
Address of student: Nashik 
Division of student: C 
---------------------------------------- 
Roll number of student: 26 
Name of the student: Prathmesh 
Address of student: Sangli 
Division of student: D 
.............File Operations.............. 
1. Add Record. 
2. Display Record. 
3. Search a particular Record. 4. Delete particular Record. 
5. Exit 
Enter your choice: 3 
Enter student roll no. whose record you want search: 26 
Record for roll no. is not found in the file.Record for roll no. is not 
found in the file. 
---------------------------------------- 
Roll number of student: 26 
Name of the student: Prathmesh 
Address of student: Sangli 
Division of student: D 
.............File Operations.............. 
1. Add Record. 
2. Display Record. 
3. Search a particular Record. 4. Delete particular Record. 
5. Exit 
Enter your choice: 4 
Enter student roll no. whose record you want delete: 26 
Record Deleted Successfully!! 
.............File Operations.............. 
1. Add Record. 
2. Display Record. 
3. Search a particular Record. 4. Delete particular Record. 
5. Exit 
Enter your choice: 2 

List of records: 
---------------------------------------- 
Roll number of student: 06 
Name of the student: Kaustubh 
Address of student: Pune 
Division of student: B 
---------------------------------------- 
Roll number of student: 11 
Name of the student: Avishkar 
Address of student: Nashik 
Division of student: C 
 
.............File Operations.............. 
1. Add Record. 
2. Display Record. 
3. Search a particular Record. 4. Delete particular Record. 
5. Exit 
Enter your choice: 5 
