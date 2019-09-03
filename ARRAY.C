#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>

int size;

void display(int size,int arr[100])
{
int i;
	printf("The array is : \n\n");
    for(i=0;i<size;i++)
    {
	printf("\t%d\n",arr[i]);
    }
}

void insertion(int size,int arr[100])
{
int el,pos,i;
char ans='y';
    printf("Enter the element to be inserted : ");
    scanf("%d",&el);

    printf("Enter the position at which element is to be inserted : ");
    scanf("%d",&pos);

    pos--;
    size=size+1;
    for(i=size;i>=pos;i--)
    {
       arr[i]=arr[i-1];
    }
    arr[pos]=el;
    display(size,arr);

     printf("Do you want to insert again...?(Y/N)\t");
    scanf(" %c",&ans);
    if(ans=='y'||ans=='Y')
	insertion(size,arr);
}

void deletion(int size,int arr[100])
{
int pos,i,item;
char ans='y';
    printf("Enter the position of the element to be deleted : ");
    scanf("%d",&pos);

    item=arr[pos-1];

    for(i=pos-1;i<size-1;i++)
    {
       arr[i]=arr[i+1];
    }
    size=size-1;
    printf("Deleted item : %d\n\n",item);
    display(size,arr);

    printf("Do you want to delete again...?(Y/N)\t");
    scanf(" %c",&ans);
    if(ans=='y'||ans=='Y')
	deletion(size,arr);
    if(size==0)
	printf("Array is empty.\n\n");
}

void searching(int size,int arr[100])
{
int el,i,flag;
char ch,ans='y';
	printf("Enter the element to be searched : \n\n");
	scanf("%d",&el);

	for(i=0;i<size;i++)
	{
	    if(arr[i]==el)
		printf("Element found at %d position.\n\n",i+1);
		flag=0;
	}
	if(flag!=0)
		printf("Element not found.\n\n");

	printf("Do you want to search again(Y/N)?\t");
	scanf(" %c",&ans);

	if(ans=='y'||ans=='Y')
	searching(size,arr);
}

void main()
{
int arr[100],i;
char ans='y',ch;
clrscr();

    printf("Enter the size of the array(max.100) : ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
	printf("Enter the %d element of the array : ",i+1);
	scanf("%d",&arr[i]);
    }
    display(size,arr);
    do{
	printf("\n\nEnter your choice(1-4): \n\n1.Display\n\n2.Insertion\n\n3.Deletion\n\n4.Searching\n\n5.Exit\n\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	    display(size,arr);
	    break;
	case 2:
	    insertion(size,arr);
	    break;
	case 3:
	    deletion(size,arr);
	     break;
	case 4:
	    searching(size,arr);
	     break;
	case 5:
	    exit(0);
	default:
	    printf("Wrong Input\n\n");
	}
	printf("Do you want to continue to the main menu...?(Y/N)\t");
	scanf(" %c",&ans);
    }while(ans=='y'||ans=='Y');
}
