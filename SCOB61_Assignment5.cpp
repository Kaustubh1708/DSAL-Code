// Assignment No. 5 
/* Problem Statement : Consider telephone book database of N clients. Make 
use of a hash table implementation 
to quickly look up client's telephone number. Make use of two collision 
handling 
techniques and compare them using number of comparisons required to find a 
set of 
telephone numbers 
*/ 
#include <iostream> 
#include <string> 

using namespace std; 

class telephone 
{
public: 

long long int mobile[10]; 
int key, address; 
string name[10]; 

void insert_linearly() 
{
int i; 
for(i=0;i<10;i++) 
{
mobile[i]=-1; 
}

string n="y"; 
do 
{
cout<<"Enter the mobile no."; 
cin>>key; 
address=key%10; 

while(1) 
{
if(mobile[address]==-1) 
{
mobile[address]=key; 
break; 
}
else 
{
address++; 
if(address==10) 
{
address=0; 
}
}
}
 
int cnt=0; 
for(int k=0;k<10;k++) 
{
if(mobile[k]!=-1) 
{
cnt++; 
}
}
if(cnt==10) 
{
cout<<"Hash table is full!!"; 
}
cout<<"Do you want to add another mobile no (y/n): "; 
cin>>n; 

}while(n=="y"); 
}


void insert_Quadratically() 
{
int i; 
for(i=0;i<10;i++) 
{
mobile[i]=-1; 
}

string n="y"; 
do 
{
cout<<"Enter the mobile no."; 
cin>>key; 
address=key%10; 

if(mobile[address]==-1) 
{
mobile[address]=key; 
}
else 
{
//when collision occurs.... 
int j=1; while(1) 
{
int t = (address + j * j) % 10; 
if (mobile[t] == -1) 
{
mobile[t] = key; 
break; 
}
else 
{
j++; 
}
 
}
}

int cnt=0; 
for(int k=0;k<10;k++) 
{
if(mobile[k]!=-1) 
{
cnt++; 
}


}
if(cnt==10) 
{
cout<<"Hash table is full!!"; 
}
cout<<"Do you want to add another mobile no (y/n): "; 
cin>>n; 
}while(n=="y"); 
}

void display() 
{
int i; 
cout<<"\n----------------Displaying Records---------------- 
"<<"\n"; 
for(i=0; i<10; i++) 
{
cout<<i<<"\t"; 
cout<<mobile[i]<<"\n"; 
}
}

void search() 
{
int k,a; 
int flag=0; 
cout<<"Enter number u want to search : "; 
cin>>k; 
a = k % 10; 
for(int i=0; i<=10;i++) 
{
if(mobile[a]==k) 
{
flag=1; 
cout<<"Number found at index 
"<<a<<"\n"; 
break; 
}
else if(mobile[a]!=k) 
{
a++; 
 
if(a==10) 
{
a=0; 
}
}
}
if(flag==0) 
{
cout<<"Number not found !!!\n"; 
}
}


}; 


int main() 
{
int choice; 
telephone obj1; 
do 
{
cout<<"\n1. Insert record using linear probing \n2. Insert record 
using Quadratic probing \n3. Display Record\n4.Search \n5. Exit."; 
cout<<"\nEnter your choice: "; 
cin>>choice; 
switch(choice) 
{
case 1: 
obj1.insert_linearly(); 
break; 
case 2: 
obj1.insert_Quadratically(); 
break; 
case 3: 
obj1.display(); 
break; 
case 4: 
obj1.search(); 
break; 
case 5: 
break; 
}

}while(choice!=5); 
return 0; 
}


/*Output : 

1. 	Insert record using linear probing 2. 	Insert record using Quadratic probing 3. 	Display Record 
 
4. Search 
5. Exit. 
Enter your choice: 1 
Enter the mobile no.65 
Do you want to add another 
Enter the mobile no.75 
Do you want to add another 
Enter the mobile no.30 
Do you want to add another 
Enter the mobile no.89 
Do you want to add another 
Enter the mobile no.86 
Do you want to add another 
Enter the mobile no.39 
Do you want to add another 
Enter the mobile no.41 
Do you want to add another 
 




mobile no (y/n): y 

mobile no (y/n): y 

mobile no (y/n): y 

mobile no (y/n): y 

mobile no (y/n): y 

mobile no (y/n): y 

mobile no (y/n): n 
 

1. Insert record using linear probing 
2. Insert record using Quadratic probing 
3. Display Record 
4. Search 5. Exit. 
Enter your choice: 3 

----------------Displaying Records---------------- 
 
0
1. 39 2. 41 3. -1 4. -1 5. 65 6. 75 7. 86 8. -1 9. 89 
 
30 
 

1. Insert record using linear probing 
2. Insert record using Quadratic probing 
3. Display Record 
4. Search 5. Exit. 
Enter your choice: 4 
Enter number u want to search : 89 
Number found at index 9 

1. Insert record using linear probing 
2. Insert record using Quadratic probing 
3. Display Record 
4. Search 5. Exit. 
Enter your choice: 4 
Enter number u want to search : 29 
Number not found !!! 
 
1. Insert record using linear probing 
2. Insert record using Quadratic probing 
3. Display Record 
4. Search 5. Exit. 
Enter your choice: 4 
Enter number u want to search : 39 
Number found at index 1 

1. Insert record using linear probing 
2. Insert record using Quadratic probing 
3. Display Record 
4. Search 5. Exit. 
Enter your choice: 2 
Enter the mobile no.65 
Do you want to add another mobile no (y/n): 	y
Enter the mobile no.75 
Do you want to add another mobile no (y/n): 	y
Enter the mobile no.30 
Do you want to add another mobile no (y/n): 	y
Enter the mobile no.86 
Do you want to add another mobile no (y/n): 	y
Enter the mobile no.89 
Do you want to add another mobile no (y/n): 	y
Enter the mobile no.39 
Do you want to add another mobile no (y/n): 	n

1. Insert record using linear probing 
2. Insert record using Quadratic probing 
3. Display Record 
4. Search 5. Exit. 
Enter your choice: 3 

----------------Displaying Records---------------- 
 
0
1. -1 2. -1 3. 39 4. -1 5. 65 6. 75 7. 86 8. -1 9. 89 
 
30 
 

1. Insert record using linear probing 
2. Insert record using Quadratic probing 
3. Display Record 
4. Search 5. Exit. 
Enter your choice: 4 
 
Enter number u want to search : 86 
Number found at index 7 

1. Insert record using linear probing 
2. Insert record using Quadratic probing 
3. Display Record 
4. Search 5. Exit. 
Enter your choice: 5 */
