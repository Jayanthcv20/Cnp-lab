#include<stdio.h>
#include<string.h>
int main()
{
   char ch,ar1[50]="01111110",ar2[50];
   int count=0,i=8,j,k=0;
   printf("Enter data to be transmitted : ");
   
   
   do
   {
       scanf("%c",&ch);
       if(ch=='\0')
            break;
       if(ch=='1') 
             count++;
          else
             count=0;
             
             ar1[i++]=ch;
             
             if(count==5)
             {
                ar1[i++]='0';
                count=0;
             }
   }while(ch!='\n');
   
   strcat(ar1,"01111110");
   printf("\n Transmitted bit stream(After stuffing) at the transmitter side is : %s",ar1);
   
   
   //destufing
    j=strlen(ar1);
    
    count=0;
    
    for(i=8;i<j-8;i++)
    {
       if(ar1[i]=='1')
         count++;
       else
         count=0;
         
       ar2[k]=ar1[i];
       k++;
       
       if(count==5 && ar1[i+1]=='0')
       {
           i++;
           count=0;
       }
    }
    ar2[k]='\0';
    printf("\n Destuffed data at te receiver is : ");
    for(i=0;i<k;i++)
    printf("%c",ar2[i]);
    return 0; 
}