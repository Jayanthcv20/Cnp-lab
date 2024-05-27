#include<stdio.h>
#include<string.h>
int main()
{
int i,j,k=0,l,n,a;
char in[40],d[50],des[50];
char sof[]="dlestx";
char eof[]="dleetx";
printf("Enter the number of characters : ");
scanf("%d",&n);
printf("Enter the character string of length %d : ",n);
scanf("%s",&in);
strcpy(d,sof);
i=strlen(sof);
for(j=0;j<n;j++)
{
   if(( in[j] == 'd' && in[j+1] == 'l' && in[j+2] == 'e') || (in[j] == 'D' && in[j+1] == 'L' && in[j+2] == 'E'))
   {
       k=1;
   }
   
   if(k==1)
   {
       k=0;
       d[i]='d';
       d[i+1]='l';
       d[i+2]='e';
       i=i+3;
   }
   d[i]=in[j];
   i=i+1;
}
d[i]='\0';
strcat(d,eof);
l=strlen(d);
printf("Length of stuffed data is : %d",l);
printf("\nThe stuffed data is : %s\n",d);
  
//destuffing 
i=6,j=0;
while(i<l-6)
{
    if(( d[i] == 'd' && d[i+1] == 'l' && d[i+2] == 'e') || (d[i] == 'D' && d[i+1] == 'L' && d[i+2] == 'E'))  
    {
       k=1;
    }
    if(k==1)
    {
       k=0;
       i=i+3;
    }
    des[j]=d[i];
    j=j+1;
    i=i+1;
}       
des[j]='\0';
printf("\n After destuffing : %s",des); 
   
return 0;
}