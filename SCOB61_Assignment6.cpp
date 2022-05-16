// Assignment No. 6 
/* Problem Statement : There are flight paths between cities. If there is 
a flight between city A and city B then 
there is an edge between the cities. The cost of the edge can be the time 
that flight take 
to reach city B from A, or the amount of fuel used for the journey. 
Represent this as a 
graph. The node can be represented by airport name or name of the city. 
Use adjacency 
list representation of the graph or use adjacency matrix representation of the graph. 
Check whether the graph is connected or not. Justify the storage 
representation used. */ 
#include <iostream> 
#include <iomanip> 
#include <string> 

using namespace std; 

int main() 
{
int ncity; 
int nedges; 

cout<<"\nEnter number of cities : "; 
cin>>ncity; 

string nameofcity ,name[ncity]; 
int mat[ncity][ncity]; 
for(int i=0; i<ncity; i++) 
{
for(int j=0; j<ncity; j++) 
{
mat[i][j] = 0; 
}
}

cout<<"\nEnter name of cities : "; 
for(int i=0; i<ncity; i++) 
{
cout<<"\nCity "<<i+1<<": "; 
cin>>nameofcity; 
name[i]=nameofcity; 
}

cout<<"Enter number of edges present : "; 
cin>>nedges; 
cout<<endl; 

for(int i=0; i<ncity; i++) 
{
cout << i <<" = "<< name[i]<<"\n"; 
}
 
int city1, city2, time; 
cout<<"Enter edges between cities : "; 
for(int i=0; i<nedges; i++) 
{
cout<<"\nEnter 1st city : "; 
cin>>city1; 
cout<<"\nEnter 2nd city : "; 
cin>>city2; 
cout<<"\nEnter time required to travel : "; 
cin>>time; 

mat[city1][city2]=time; mat[city2][city1]=time; 
}

cout<<"\nAdjacency matrix representation of graph : \n"; 
for(int i=0; i<ncity; i++) 
{
cout<<"\t"<<setw(5)<<name[i]; 
}
cout<<endl; 
for(int i=0; i<ncity; i++) 
{
cout<<setw(5)<<name[i]<<"\t"; 
for(int j=0; j<ncity; j++) 
{
cout<< setw(5) << mat[i][j]<<"\t"; 
}
cout <<endl; 
}

return 0; 
}


/*Output : 

Enter number of cities : 4 

Enter name of cities : 
City 1: Pune 

City 2: Mumbai 

City 3: Nashik 

City 4: Thane 
Enter number of edges present : 5 

0 = Pune 
1. = Mumbai 2. = Nashik 
3. = Thane 
Enter edges between cities : 
 
Enter 1st city : 0 

Enter 2nd city : 1 

Enter time required to travel : 60 

Enter 1st city : 1 

Enter 2nd city : 2 

Enter time required to travel : 80 

Enter 1st city : 2 

Enter 2nd city : 3 

Enter time required to travel : 94 

Enter 1st city : 0 

Enter 2nd city : 3 

Enter time required to travel : 46 

Enter 1st city : 0 

Enter 2nd city : 2 

Enter time required to travel : 85 

Adjacency matrix representation of graph : 
Pune 	Mumbai Nashik Thane 
Pune 	0	60 	85 	46 Mumbai 	60 	0	80 	0Nashik 	85 	80 	0	94 Thane 	46 	0	94 	0*/
