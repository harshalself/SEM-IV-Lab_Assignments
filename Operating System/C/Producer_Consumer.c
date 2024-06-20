//write a c program to implement producer consumer problem
#include<stdio.h>
int mutex=1;
int full=0;
int empty=3;
int x=0;
int main()
{
int n;
void producer();
void consumer();
int wait(int);
int signal(int);
printf("\n 1.producer \n 2.consumer ");
while(1)
{
printf("\nenter your choice");
scanf("%d",&n);
switch(n)
{
case 1:
if((mutex==1)&&(empty!=0))
producer();
else
printf("buffer is full");
break;
case 2:
if((mutex==1)&&(full!=0))
consumer();
else
printf("buffer is empty");
break;
}
}
return(0);
}
int wait(int s)
{
return(--s);
}
int signal(int s)
{
return(++s);
}
void producer()
{
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
x++;
printf("\nproducer produces the item%d",x);
mutex=signal(mutex);
}
void consumer()
{ 
mutex=wait(mutex);
full=wait(full);
empty=signal(empty);
printf("consumer consumes the item %d",x);
x--;
mutex=signal(mutex);
}