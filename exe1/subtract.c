#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)<(b)?(b):(a))
int main()
{
    char str1[100]={'\0'},str2[100]={'\0'};
    char res[100]={'\0'};
    fgets(str1,100,stdin);
    fgets(str2,100,stdin);
    int flag = 1;
    int len1 = strlen(str1)-1,len2 = strlen(str2)-1;
    if(len1 <len2 || (len1 == len2 && strcmp(str1,str2)<0))
    {
        char temp[100]={'\0'};
        strcpy(temp,str1);
        strcpy(str1,str2);
        strcpy(str2,temp);
        flag = 0;
    }
    len1 = strlen(str1)-1;
    len2 = strlen(str2)-1;
    for(int i=0; i<=len1-1;i++)
    {
        int num1 = str1[len1-1-i]-'0',num2 = 0 ;
        if(i<=len2-1)
        {
            num2 = str2[len2-1-i]-'0';
        }
        if(num1 < num2)
        {
            res[i] = num1+10-num2+'0';
            str1[len1-1-i-1]--;           
        }
        else
        {
            res[i] = num1-num2+'0';
        }
    }
    if(flag==0)
    {
        printf("-");
    }
    int zero = 1;
    for(int i=strlen(res)-1;i>=0;i--)
    {
        if(res[i]!='\0')
        {
            if(res[i]!='0')
                zero = 0;
            if(zero == 0)
                printf("%c",res[i]);
        }
    }
    if (zero == 1)
    {
        printf("0");
    }
    
}