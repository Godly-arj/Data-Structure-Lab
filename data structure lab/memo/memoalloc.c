#include <stdio.h>
#include <stdlib.h>
struct node
{
int memblock;
struct node *left;
struct node *right;
} *head, *temp, *dele;
void insert(int value)
{
struct node *newnode = (struct node *)malloc(sizeof(struct node));
newnode->memblock = value;
newnode->left = NULL;
newnode->right = NULL;
if (head == NULL)
{
head = newnode;
}
else
{
temp = head;
while (temp->right != NULL)
{
temp = temp->right;
}
newnode->left = temp;
temp->right = newnode;
}
}
void display()
{
temp = head;
printf("\nMEMORY: ");
while (temp != NULL)
{
printf("%d ", temp->memblock);
temp = temp->right;
}
}
int alloc(int x)
{
int j = -1;
temp = head;
while (temp != NULL)
{
if ((temp->memblock) >= x)
{
j = temp->memblock;
break;
}
temp = temp->right;
}
return j;
}
void del(int k)
{
temp = head;
while (temp != NULL)
{
if (temp->memblock == k)
{
if (temp->left == NULL)
{
dele = temp;
free(dele);
temp->right->left = NULL;
head = temp->right;
}
else if (temp->right == NULL)
{
temp->left->right = NULL;
free(temp->right);
}
else
{
temp->left->right = temp->right;
temp->right->left = temp->left;
}
}
temp = temp->right;
}
}
int main()
{
insert(300);
insert(500);
insert(450);
insert(200);
insert(100);
insert(50);
int x;
int k, choice;
char ch;
do
{
printf("\n1.Allocate memory:\n2.Deallocate memory\nEnter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter the memory needed: ");
scanf("%d", &x);
k = alloc(x);
if (k == -1)
{
printf("Couldn't allocate\n");
}
else
{
printf("%d was allocated\n", k);
del(k);
}
break;
case 2:
printf("Enter the memory to be deallocated: ");
scanf("%d", &x);
insert(x);
}
printf("\nDo you want to continue? ");
scanf(" %c", &ch);
} while (ch == 'y' || ch == 'Y');
display();
return 0;
}