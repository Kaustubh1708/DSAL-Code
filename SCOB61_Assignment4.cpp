// Assignment No. 4 
/* Problem Statement : A Dictionary stores keywords & its meanings. 
Provide facility for adding new keywords, 
deleting keywords, updating values of any entry. Provide facility to 
display whole data 
sorted in ascending/ Descending order. Also find how many maximum 
comparisons may 
require for finding any keyword. Use Binary Search Tree for 
implementation. */ 
#include <iostream> #include <string.h> 
using namespace std; 

class Node 
{
public: 
string word, mean; 
Node *left, *right; 
}; 
class tree 
{
public: 
Node *root; 
int flag = 0; 
Node *creat_tree() 
{
root = new Node(); 
cout << "Enter the word =>"; 
cin >> root->word; 
cout << "Enter the meaning =>"; 
cin >> root->mean; root->left = NULL; 
root->right = NULL; 
return root; 
}
void insert(string word_, string meaning, Node *root) 
{
if (root->word.compare(word_) > 0) 
{
if (root->left == NULL) 
{
Node *node = new Node(); 
root->left = node; 
node->word = word_; 
node->mean = meaning; 
}
else 
{
insert(word_, meaning, root->left); 
}
}
else 
{
if (root->word.compare(word_) < 0) 
 
{
if (root->right == NULL) 
{
Node *node = new Node(); 
root->right = node; node->word = word_; 
node->mean = meaning; 
}
else 
{
insert(word_, meaning, root->right); 
}
}
}
}
void inorder(Node *root) 
{
if (root != NULL) 
{
inorder(root->left); 
cout << "word=> " << root->word << " meaning=> " << root->mean 
<< endl; 
inorder(root->right); 
}
}
void inorder_dis(Node *root) 
{
if (root != NULL) 
{
inorder_dis(root->right); 
cout << "word=> " << root->word << " meaning=> " << root->mean 
<< endl; 
inorder_dis(root->left); 
}
}
Node *search(string key, Node *root) 
{
if (root->word.compare(key) > 0) 
{
if (root->left == NULL) 
{
cout << "\nWord found \n"; 
}
else 
{
search(key, root->left); 
}
}
else if (root->word.compare(key) < 0) 
{
if (root->right == NULL) 
{
cout << "\nWord found\n"; 
}
 
else 
{
search(key, root->right); 
}
}
else if (root->word.compare(key) == 0) 
{
cout << "\nWord found\n"; 

return root; 
}
}

void search_(string key, Node *root) 
{
if (root->word.compare(key) > 0) 
{
if (root->left == NULL) 
{
cout << "\nWord is not found \n"; 
}
else 
{
search_(key, root->left); 
}
}
else if (root->word.compare(key) < 0) 
{
if (root->right == NULL) 
{
cout << "\nWord is not found \n"; 
}
else 
{
search_(key, root->right); 
}
}
else if (root->word.compare(key) == 0) 
{
string meaning; 
cout << "Enter the meaning =>"; 
cin >> meaning; 
root->mean = meaning; 
cout << "Replaced"; 
}
}
void replace() 
{
Node *a; 
string key; 
cout << "Enter the word of which meaning to have changed=> "; 
cin >> key; 
search_(key, root); 
}
 
void search_count(string key, Node *root ,int *count) 
{	if (root->word.compare(key) > 0) 
{
(*count)++; 

cout<<"The count is "<<*count; 
// return *count; 
}
else if (root->word.compare(key) > 0) 
 
{









}
else 
{









}
 
(*count)++; (*count)++; 
if (root->left == NULL) 
{
cout<<"The count is ",*count; 
}
else 
{
search_count(key, root->left,count); 
}


(*count)++; (*count)++; 
if (root->right == NULL) 
{
cout<<"The count is "<<*count; 
}
else 
{
search_count(key, root->right,count); 
}
 

}
Node *Successor(Node *root) 
{
Node *Successor = root; 
while (Successor->left != NULL) 
{
Successor = Successor->left; 
}
return Successor; 
}

Node *delete_(Node *root, string Keyword) 
{
if (root != NULL) 
{
if (Keyword == root->word) 
{
if (root->left == NULL) 
{
Node *temp = root->right; 
 
free(root); 
cout << "\nThe word has been deleted 
successfully.\n\n"; 
return temp; 
}
else if (root->right == NULL) 
{
Node *temp = root->left; 
free(root); 
cout << "\nThe word has been deleted 
 
successfully.\n\n"; 

}
else 
{




}
}
 

return temp; 



Node *temp = Successor(root->right); 
root->word = temp->word; root->mean = temp->mean; 
root->right = delete_(root->right, temp->word); 
 
else if (Keyword.compare(root->word) < 0) 
root->left = delete_(root->left, Keyword); 
else 
root->right = delete_(root->right, Keyword); 
}
else 
cout << "\n\nValue not found.\n\nThe word " << Keyword << " is 
not present in the dictionary.\n\n"; 
return root; 
}
}; 
int main() 
{
int ch, flag = 0; 
int Long,a; 
tree obj; 
Node *root; 
string key, ser, word, mean, str; 
int count=0; 
do 
{
cout << "\n1. Add the node \n2. Display \n3. Search\n4.replace 
\n5.delete \n6. Exit\nenter choice =>"; 
cin >> ch; 
switch (ch) 
{
case 1: 
int no; 
cout << "Enter how many words you want to add => "; 
cin >> no; 
for (int k = 0; k < no; k++) 
{
// cout << "\nEnter the word=> "; 
 
// cin >> key; 
if (flag == 0) 
{
root = obj.creat_tree(); 
flag = 1; 
}
else 
{
cout << "Enter the word=>"; 
cin >> word; 
cout << "Enter the meaning=>"; 
cin >> mean; 
obj.insert(word, mean, root); 
}
}
break; 
case 2: 
cout << "\nAssending\n"; 
obj.inorder(root); 
cout << "\n"; 
cout << "\nDescending\n"; 
obj.inorder_dis(root); 

break; 
case 3: 
cout << "Enter the word you want to search => "; 
cin >> ser; 
obj.search(ser, root); 
obj.search_count(ser, root,&count); 
// cout<<"\n"<<a; 
break; 
case 4: 
obj.replace(); 
break; 
case 5: 
cout << "Enter the word=>"; 
cin >> str; 
obj.delete_(root, str); 
break; 
case 6: 
break; 
}
} while (ch != 6); 
}

/*
Output : 
 

1. 2. 3. 4. 5. 6. 
 

Add the node 
Display 
Search 
replace 
delete 
Exit 
 
 
enter 
Enter Enter Enter Enter Enter Enter Enter Enter Enter 
 
choice =>1 
how many words you want to add => 4 
the word =>ABC 
the meaning =>abc 
the word=>XYZ 
the meaning=>xyz 
the word=>PQR 
the meaning=>pqr 
the word=>LMN 
the meaning=>lmn 
 

1. Add the node 
2. Display 
3. Search 
4. replace 
5. delete 
6. Exit 
enter choice =>2 

Assending 
 
word=> ABC word=> LMN word=> PQR word=> XYZ 


Descending word=> XYZ word=> PQR word=> LMN word=> ABC 
 
meaning=> meaning=> meaning=> meaning=> 



meaning=> meaning=> meaning=> meaning=> 
 
abc lmn pqr xyz 



xyz pqr lmn abc 
 

1. Add the node 
2. Display 
3. Search 
4. replace 
5. delete 
6. Exit 
enter choice =>3 
Enter the word you want to search => PQR 

Word found 
The count is 3 
1. Add the node 
2. Display 
3. Search 
4. replace 
5. delete 
6. Exit 
enter choice =>4 
Enter the word of which meaning to have changed=> PQR 
Enter the meaning =>pqrs 
Replaced 
1. Add the node 
 
2. Display 
3. Search 
4. replace 
5. delete 
6. Exit 
enter choice =>2 

Assending 
 
word=> ABC word=> LMN word=> PQR word=> XYZ 


Descending word=> XYZ word=> PQR word=> LMN word=> ABC 
 
meaning=> meaning=> meaning=> meaning=> 



meaning=> meaning=> meaning=> meaning=> 
 
abc lmn 
pqrs 
xyz 



xyz 
pqrs 
lmn abc 
 

1. Add the node 
2. Display 
3. Search 
4. replace 
5. delete 
6. Exit 
enter choice =>5 
Enter the word=>PQR 

The word has been deleted successfully. 


1. Add the node 
2. Display 
3. Search 
4. replace 
5. delete 
6. Exit 
enter choice =>2 

Assending 
word=> ABC meaning=> abc word=> LMN meaning=> lmn word=> XYZ meaning=> xyz */


Descending 
word=> XYZ meaning=> xyz word=> LMN meaning=> lmn word=> ABC meaning=> abc 

1. 	Add the node 2. 	Display 3. 	Search 
 
4. replace 
5. delete 
6. Exit 
enter choice =>6
