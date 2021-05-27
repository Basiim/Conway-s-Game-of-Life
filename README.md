# Conway-s-Game-of-Life
CONWAY’S GAME OF LIFE
Introduction
The game of life is a cellular automaton devised by British mathematician John Horton Conway (Wikipedia, n.d.). The game takes its initial state as input and requires no further input. It generates next generations based on the input that user entered in initial state. It applies some rules on the input and produces next generation of cells.
Rules
The game of life contains two types of cells “*” as alive cell and “ “(space) as dead cell.
Every cell in the game interacts with eight neighboring cells top, bottom, left, right and diagonals. The following rules are applied on the basis of neighbor count around a cell in a generation.
•	Any live cell with fewer than two live ( “*” ) neighbors die, as if by underpopulation.
•	Any live cell with more than four live ( “*” ) neighbors die, as if by overpopulation.
•	Any live cell with exactly two or three live ( “*” ) neighbors lives and move on to the next generation.
•	Any dead cell with exactly three live neighbors becomes live cell, as if by reproduction.
The next generation is calculated by applying the above rules on each cell of the universe of Conway’s game of life.
Logic
To recreate this game in C I had to come up with some logics on how this game would move on.
At first, I had a lot of questions like, how would we detect eight neighbors? , how to fill an array specifically with “*” and “ “ using rand(); function? , how to swap an array? , how to detect boundary cases?
After a lot of thinking and research I came up with answers to all these questions.
Filling the grid automatically with “*” and “ “:
For this I made two functions using rand(); The first one printed “*” and the second one printed “ “.

rand()%(42-41)+42;/// Prints '*'
rand()%(32-31)+32;/// Prints ' '


Now the problem was how to tell the program to randomly chose between these two functions. For that I used an integer variable with garbage value and I put a check if the integer is completely divisible by 2 it will print “ “ otherwise print ”*”.
    
    x=rand();
    if(x%2!=0)
    {
    array_1[r][c]=rand()%(42-41)+42;/// Prints '*'
    }
    if(x%2==0)
    {
    array_1[r][c]=rand()%(32-31)+32;/// Prints ' '
    }


Detection of neighbors:
For example, in a grid of 3x3 the pointer is pointing at the middle value and it has eight neighbors to detect them all we will add different offsets into the value of pointer to move its location and detect its neighbors.

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


If the pointer is in middle then pointer-1 will always detect the value at the left of the pointer. Similarly, pointer+1 will always detect the value at right of the pointer. 


                            13  14  15  16  17
                            18  19  20  21  22   
                            23  24  25  26  27     
                            28  29  30  31  32     
                            33  34  35  36  37


Now suppose we have a 3x3 grid meaning there are three rows and three columns. If we want to detect the value directly above the pointer we will minus the number of columns (n) from the pointer i.e. pointer-n. For example, let’s suppose the pointer is at 20 in the above grid. As we can see the grid is 5x5 if we subtract 5 from 20 we get 15 which is on top of 20. Similarly to get the bottom value we add 5 (or the number of columns) into the current location of the pointer.
Now to detect the top diagonals, we want to detect the top left suppose the pointer is at 20 now we know that if we subtract 5 we get the location of top. We will subtract (n+1) from the pointer. In this case that would be 20-(5+1) = 14 Hence we will get its value. Similarly to detect top right we will subtract (n-1) from the pointer. In this case that would be 20-(5-1) = 16.
Now to detect bottom diagonals, suppose the pointer is at 20 we know that if we add 5, we get the location of bottom. If we add (n+1) to the pointer. In this case 20+(5+1)=26 we get the bottom right location. Similarly if we add (n-1) to the pointer. In this case 20+(5-1)=24 we get the bottom left value.
How to swap a 2D array:
For this task I swapped the array after calling the next_tick function in main function. I created a nested loop and copied the value of array_2 into array_1 using the coordinates in nested loop
    
   for(int r=0;r<m;r++)///Swap
    {
        for(int c=0;c<n;c++)
        {
        array_1[r][c]=array_2[r][c];
        }
    }


How to detect boundary cases:
This was perhaps the hardest task of this code and it took me days to figure out how to finally do it. For this task I used the address of pointer and stored it in two variables (ptr_addr, address) I kept the value of variable “address” the same and incriminated the value of ptr_addr in each iteration of the loop.

/*********** Top left ***************/
if((ptr_addr-address)==0)
   
/*********** Top right ***************/
if(((ptr_addr+1)-address)==n)
   
/************ Bottom left ***************/
if((ptr_addr-address)==n*(m-1))
   
/*************** Bottom Right*************/
if(((ptr_addr+1)-(address))==m*n)

/************ Top ******************/
if(((ptr_addr-(address-1))<n)&&(ptr_addr-address!=0)&&(flag==1))

/************ left ******************/
if((((ptr_addr-(address))%n)==0)&&(ptr_addr-(address)!=(n*m)-n)&&(flag==2))
   
/************ Bottom ******************/
if(((address+(m*n-n))<ptr_addr)&&((address+(m*n-1))>ptr_addr))

/************ Right ******************/
if((((ptr_addr-(address-1))%n)==0)&&(ptr_addr-(address-1) != n)&&(ptr_addr-(address-1) != n*m))
   
 /**************** Mid *******************/
if((ptr_addr-(address-1)>=n+2)&&(ptr_addr-(address)<=n*m-(n+2))&&((ptr_addr-(address-1))%n!=0)&&((ptr_addr-(address))%n!=0))


For example:
These are the addresses of elements in the array.


                            13  14  15  16  17
                            18  19  20  21  22   
                            23  24  25  26  27     
                            28  29  30  31  32     
                            33  34  35  36  37


Initially both variables address and ptr_addr are 13. And ptr_addr increases by 1 after every iteration.
•	To detect top left I used ptr_addr-address=0. In this case initially 13-13=0.
•	To detect top right I used (ptr_addr+1)-address=n. In this case (17+1)-13=5.
•	To detect bottom left I used ptr_addr-address=n*m-1. In this case 33-13=20=5*(5-1)
•	To detect bottom right I used (ptr_addr+1)-address=m*n. In this case (37+1)-13=25=5*5
Now the detection of Top, left, bottom, right and mid cases was a bit complicated as it required ranges.
•	To detect top I used (ptr_addr-(address-1))<n) and (ptr_addr-address!=0) in this the first part checks that ptr_addr-(address-1) should be less than n and the second part checks ptr_addr-address should not be equal to 0. In this case suppose the pointer is at 15. 15-13=2 <5 and it is not equal to zero.
•	To detect bottom I used ((address+(m*n-n))<ptr_addr) and ((address+(m*n-1))>ptr_addr). Suppose the pointer is at 35 according to my equation ((13+(5*5-5))=33<35 this will check the left limit and ((13+(5*5-1))=37>35 this checks the right limit. If we suppose pointer is at 33 applying in equation. 13+(5*5-5)=33 which is not less than 33 hence the statement would be false.
•	To detect left I used (ptr_addr-(address))%n)==0) and (ptr_addr-(address)!=(n*m)-n). In this case suppose the pointer is at 23. Applying in equation (23-13)%5=0 which checks the left limit and 23-13=10 which is not equal to (5*5)-5=20 which the top and bottom left corners. Suppose the pointer is at 24. 24-13=11 is not completely divided by 5 hence the statement becomes false.
•	To detect right I used (ptr_addr-(address-1))%n)==0) and (ptr_addr-(address-1) != n) and(ptr_addr-(address-1) != n*m) First one the same as in left case second checks that pointer is not on top right and third checks that pointer is not on bottom right. Suppose the pointer is at 22. Applying in equation 22-(13-1)%5=0 and 22-12=10 which is not equal to 5 and 25. Now suppose the pointer is on 17. Applying in equation (17-12)%5=0 is true but 17-12=5 and it should not be equal to 5 hence the statement becomes false.
Result
After all the calculation of neighbors the program has to decide whether the cell is going to live or die in the next generation for that I used the following piece of code.

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


This checks if the current location of pointer has “*” or “ “ and applies the rules of the game accordingly to ptr_next which is pointing towards array_2. After all iterations array_2 becomes the next generation and array_1 becomes previous generation. The I copied the values of array_2 into array_1 and repeated the process until user inputs Q from keyboard.
