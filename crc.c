#include<stdio.h>
#include<string.h>
int main()
{
char data[20]="1101101",div[10]="10101",q[20],r[10];
int len_data=strlen(data);
int len_div=strlen(div);
printf("The data is : %s",data);
char pad_data[20];
int k,l;
l=len_data+len_div-1;
strcpy(pad_data,data);
for(k=7;k<l;k++)
{
   pad_data[k]='0';
}
pad_data[l]='\0';
printf("\nPadded data : %s",pad_data);

int i,j,temp;
for(i=0;i<len_data;i++)
{
   temp=i;
   if(pad_data[temp]=='1')
   {
      for(j=0;j<len_div;j++)
      {
         if(pad_data[temp]==div[j])
         {
            pad_data[temp]='0';
            r[j]='0';
         }
         else
         {
         pad_data[temp]='1';
         r[j]='1';
         }
         temp=temp+1;
       }
       q[i]='1';
    }
    else
    q[i]='0';
}

//to remove first digit of remainder
int len_rem=strlen(r);
for(k=0;k<len_rem;k++)
{
   r[k]=r[k+1];
}

int t=len_rem-1;
r[t]='\0';
printf("\nThe quotient is : %s",q);
printf("\nThe remainder is : %s",r);
strcat(data,r);
printf("\nThe code word : %s",data);
 
int len_code=strlen(data);
char rem[10];
for(i=0;i<len_code;i++)
{
    temp=i;
    if(data[temp]=='1')
    {
         for(j=0;j<len_div;j++)
         {
            if(data[temp]==div[j])
            {
               data[temp]='0';
               rem[j]='0';
             }
             else
             {
                data[temp]='1';
                rem[j]='1';
             }
             temp=temp+1;     
          }          
     }       
}
printf("\nRemainder is : %s\n",rem);
return 0;
}