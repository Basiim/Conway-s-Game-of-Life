#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conway.h"
int main()
{
    int m,n;///Variables
    char choice,a,x;///Variables
    printf("Enter the number of rows: ");///Input rows
    scanf("%d",&m);
    printf("Enter the number of columns: ");///Input columns
    scanf("%d",&n);
    char array_1[m][n];///Array1
    char array_2[m][n];///Array2
    char *ptr_1=&array_1[0][0];///Pointer
    char *ptr_2=&array_2[0][0];///Pointer
    printf("Do you want to fill grid yourself (Y/N): ");
    scanf(" %c", &choice);
    if(choice=='Y'||choice=='y')///Manual grid fill
    {
        for(int r=0;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                a = getchar();
                printf("\nEnter state('*' for alive 'space' for dead)at index (%dx%d): ",r,c);
                a = getchar();
                array_1[r][c]=a;
            }
        }
    }
    if(choice=='N'||choice=='n')///Automatic grid fill
    {
        srand(time(0));
        for(int r=0;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                x=rand();
                if(x%2!=0)
                {
                array_1[r][c]=rand()%(42-41)+42;/// Prints '*'
                }
                if(x%2==0)
                {
                array_1[r][c]=rand()%(32-31)+32;/// Prints ' '
                }
            }
        }
    }
    for(int r=0;r<m;r++)///Print Input array
    {
        for(int c=0;c<n;c++)
        {
            printf("%c ",array_1[r][c]);
        }
        printf("\n");
    }
    for(char ch;ch!='@';)///Function call Loop
    {

       ch=getch();
        if(ch=='q'||ch=='Q')///Q to quit any other key to move to next generation
        {
            return 0;
        }
        next_tick(ptr_1,ptr_2,m,n);///Function call
        for(int r=0;r<m;r++)///Swap
        {
            for(int c=0;c<n;c++)
            {
            array_1[r][c]=array_2[r][c];
            }
        }
        system("CLS");
        for(int r=0;r<m;r++)///Print next generation
        {
            for(int c=0;c<n;c++)
            {
                printf("%c ",array_1[r][c]);
            }
            printf("\n");
        }
    }
    return 0;
}
void next_tick(char *ptr_prev, char *ptr_next, int m, int n)
{
    int flag=0,address=&ptr_prev,ptr_addr;///Variables
    /***************** Cases ***************/
    for(int i=0;i<(m*n);i++)///Main Loop
    {
     int neighbour=0;
     if(flag==0)
     {
     ptr_addr = &ptr_prev;
     flag++;
     }
     /****************** Mid *******************/
        if((ptr_addr-(address-1)>=n+2)&&(ptr_addr-(address)<=n*m-(n+2))&&((ptr_addr-(address-1))%n!=0)&&((ptr_addr-(address))%n!=0))
        {
        if(*(ptr_prev-1)=='*')///Left
         {
             neighbour++;
         }

        if(*(ptr_prev+1)=='*')///Right
         {
             neighbour++;
         }
        if(*(ptr_prev-(n-1))=='*')///Top Right
         {
            neighbour++;
         }
         if(*(ptr_prev-n)=='*')///Top Mid
         {
            neighbour++;
         }
         if(*(ptr_prev-(n+1))=='*')///Top left
         {
            neighbour++;
         }
         if(*(ptr_prev+(n+1))=='*')///Bottom right
         {
            neighbour++;
         }
         if(*(ptr_prev+(n))=='*')///Bottom mid
         {
            neighbour++;
         }
         if(*(ptr_prev+(n-1))=='*')///Bottom left
         {
            neighbour++;
         }
        }

        /*************** Bottom Right*************/
       if(((ptr_addr+1)-(address))==m*n)
        {
            if(*(ptr_prev-1)=='*')///left
            {
                neighbour++;
            }
            if(*(ptr_prev-(n+1))=='*')///Top left
            {
                neighbour++;
            }
            if(*(ptr_prev-(n))=='*')///Top Mid
            {
                neighbour++;
            }
            flag++;
        }

         /*********** Top right ***************/
        if(((ptr_addr+1)-address)==n)
         {
            if(*(ptr_prev+1)=='*')///left
            {
                neighbour++;
            }
            if(*(ptr_prev+(n-1))=='*')///Bottom left
            {
                neighbour++;
            }
            if(*(ptr_prev+(n))=='*')///Bottom mid
            {
                neighbour++;
            }
            flag++;
         }

        /*********** Top left ***************/
       if((ptr_addr-address)==0)
        {
            if(*(ptr_prev+1)=='*')///Right
            {
                neighbour++;
            }
            if(*(ptr_prev+(n+1))=='*')///Bottom right
            {
                neighbour++;
            }
            if(*(ptr_prev+(n))=='*')///Bottom mid
            {
                neighbour++;
            }
        }

        /************ Bottom left ***************/
       if((ptr_addr-address)==n*(m-1))
        {
            if(*(ptr_prev+1)=='*')///Right
            {
                neighbour++;
            }
            if(*(ptr_prev-n)=='*')///Top Mid
            {
                neighbour++;
            }
            if(*(ptr_prev-(n-1))=='*')///Top right
            {
                neighbour++;
            }
        }

        /************ Top ******************/
       if(((ptr_addr-(address-1))<n)&&(ptr_addr-address!=0)&&(flag==1))
        {
            if(*(ptr_prev+(n))=='*')///bottom
            {
                neighbour++;
            }
            if(*(ptr_prev+1)=='*')///Right
            {
                neighbour++;
            }
            if(*(ptr_prev-1)=='*')///Left
            {
                neighbour++;
            }
            if(*(ptr_prev+(n+1))=='*')///bottom right
            {
                neighbour++;
            }
            if(*(ptr_prev+(n-1))=='*')///Bottom left
            {
                neighbour++;
            }
        }
        /************ Bottom ******************/
        if(((address+(m*n-n))<ptr_addr)&&((address+(m*n-1))>ptr_addr))
        {
            if(*(ptr_prev-n)=='*')///Top
            {
                neighbour++;
            }
            if(*(ptr_prev+1)=='*')///Right
            {
                neighbour++;
            }
            if(*(ptr_prev-1)=='*')///Left
            {
                neighbour++;
            }
            if(*(ptr_prev-(n-1))=='*')///top right
            {
                neighbour++;
            }
            if(*(ptr_prev-(n+1))=='*')///Top left
            {
                neighbour++;
            }
        }
        /************ left ******************/
        if((((ptr_addr-(address))%n)==0)&&(ptr_addr-(address)!=(n*m)-n)&&(flag==2))
        {
            if(*(ptr_prev-n)=='*')///Top
            {
                neighbour++;
            }
            if(*(ptr_prev+n)=='*')///bottom
            {
                neighbour++;
            }
            if(*(ptr_prev-(n-1))=='*')///Top right
            {
                neighbour++;
            }
            if(*(ptr_prev+(n+1))=='*')///bottom right
            {
                neighbour++;
            }
            if(*(ptr_prev+1)=='*')///Left
            {
                neighbour++;
            }
        }
        /************ Right ******************/
        if((((ptr_addr-(address-1))%n)==0)&&(ptr_addr-(address-1) != n)&&(ptr_addr-(address-1) != n*m))
        {
            if(*(ptr_prev-n)=='*')///Top
            {
                neighbour++;
            }
            if(*(ptr_prev+n)=='*')///bottom
            {
                neighbour++;
            }
            if(*(ptr_prev+1)=='*')///Right
            {
                neighbour++;
            }
            if(*(ptr_prev-(n+1))=='*')///Top left
            {
                neighbour++;
            }
            if(*(ptr_prev+(n-1))=='*')///Bottom left
            {
                neighbour++;
            }
        }

         /************** Result **************/
        if(*(ptr_prev)==' ')
        {
            if(neighbour==3)
                *(ptr_next)='*';
            if(neighbour<3 || neighbour>3)
                *(ptr_next)=' ';
        }
        if(*(ptr_prev)=='*')
        {
            if(neighbour>=4)
                *(ptr_next)=' ';
            if(neighbour<2)
                *(ptr_next)=' ';
            if(neighbour==2||neighbour==3)
                *(ptr_next)='*';
        }
        ptr_prev++;///Moving pointers
        ptr_addr++;
        ptr_next++;
    }
}
