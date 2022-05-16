//Assignment No. 1 
/* Problem Statement: A book consists of chapters, chapters consist of 
sections and sections consist of 
subsections. Construct a tree and print the nodes. Find the time and space 
requirements 
of your method. */ 
#include <iostream> #include <string.h> 
using namespace std; 

struct node // Node Declaration 
{
char label[10]; 
int ch_count; 
struct node *child[10]; 
}*root; 

class Book // Class Declaration 
{
public: 

Book() 
{
root = NULL; 
}


void create() 
{
int tbooks, tchapters, tsections, i, j, k; 

root = new node; 
cout << "Enter head of book : "; 
cin>>root->label; 

cout << "Enter number of chapters in book : "; 
cin >> tchapters; 
root->ch_count = tchapters; 
for (i = 0; i < tchapters; i++) 
{
root->child[i] = new node; 
cout << "Enter the name of Chapter " << i + 1 << " : "; 
cin>>root->child[i]->label; 

cout << "Enter number of sections in Chapter " << root- 
>child[i]->label << " : "; 
cin >> tsections; 
root->child[i]->ch_count = tsections; 

for (j = 0; j < tsections; j++) 
{
root->child[i]->child[j] = new node; 
cout << "Enter the name of section " << j+1 << " : "; 
cin>>root->child[i]->child[j]->label; 
 
}
}
}

void display(node *r1) 
{
cout<<"\n\n******************"<<r1- 
>label<<"******************"<<endl; 

for(int i=0; i<r1->ch_count;i++) 
{
cout<<"\n"<<i+1<<"\t"<<r1->child[i]->label; 
for (int j=0; j<r1->child[i]->ch_count; j++) 
{
cout<<"\n\t"<<j+1<<"\t"<<r1->child[i]->child[j]->label; 
}
cout<<"\n---------------------------------------------------"; 
}

}


}; 


int main() 
{
Book b1; 

b1.create(); 
b1.display(root); 

return 0; 
}

/*Output: 
Enter head of book : DSA 
 
Enter number of chapters in Enter the name of Chapter 1 Enter number of sections in Enter the name of section 1 Enter the name of section 2 Enter the name of section 3 Enter the name of Chapter 2 Enter number of sections in Enter the name of section 1 Enter the name of section 2 Enter the name of Chapter 3 Enter number of sections in Enter the name of section 1 Enter the name of section 2 
 
book : 3 
: Graph 
Chapter Graph : 3 : Adjacencymatrix 
: DFS : BFS 
: Tree 
Chapter Tree : 2 
: General 
: Binary 
: Hashing 
Chapter Hashing : 2 
: Probing 
: Chaining 
 


******************DSA****************** 
 
1. Graph 
1. Adjacencymatrix 
2. DFS 3. BFS 
--------------------------------------------------- 
4. Tree 
1. General 
2. Binary 
--------------------------------------------------- 
3. Hashing 
1. Probing 
2. Chaining 
--------------------------------------------------- */
