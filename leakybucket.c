
#include<stdio.h>
#include<stdlib.h>
#define bucketsize 860

void bktinput(int a,int b)
{
if(a>bucketsize)
     printf("\nPacket discarded\n");
else
     {
        //sleep(1);
        while(a>b)
        {
            printf("\n%dBytes outputted",b);
            a-=b;
           // sleep(2);
        }
        if(a>0)
               printf("\nLast %d bytes sent",a);
        printf("\nBucket output successful\n");
      }             
}

int main()
{
int op,i,pktsize;
printf("Enter Output rate : ");
scanf("%d",&op);
for(i=1;i<=5;i++)
{
   sleep(1);
   pktsize=random()%1000;
   printf("\nPacket number : %d\t Packet size : %d",i,pktsize);
   bktinput(pktsize,op);
}
return 0;
}   
