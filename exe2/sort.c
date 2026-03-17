#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h> 
#define MAXLINE 1024
int main()
{
    int n;
    scanf("%d",&n);
    char name[100][30]={'\0'};
    char number[100][12]={'\0'};
    int find[100]={0};
    char final_name[100][50]={'\0'};
    for(int i=0;i<n;i++)
    {
        scanf("%s %s",name[i],number[i]);
    }
    // int maxlength = 0;
    // for (int i =0;i<n;i++)
    // {
    //     int len = strlen(haoma_bu[i]);
    //     if(len > maxlength)
    //         maxlength = len;
    // }
    // for(int i=0;i<n;i++)
    // {
    //     printf("%s %s\n",name[i],number[i]);
    // }
    int f=0;
    for(int i=0;i<n;i++)
    {
        if(find[i]!=0)
        {
            continue;
        }
        strcpy(final_name[f],name[i]);
        final_name[f][strlen(final_name[f])]=' ';
        strcat(final_name[f],number[i]);
        f++;
        char same_name='0'; 
        for(int k=i+1;k<n;k++)
        {
            if(find[k]!=0)
            {
                continue;
            }
            if(strcmp(name[i],name[k])==0)
            {
                same_name++;
                find[k]=1;
                if(strcmp(number[i],number[k])==0)
                {
                    same_name--;
                    find[k]=2;
                }
                if(find[k]==1)
                {
                    name[k][strlen(name[k])]='_';
                    name[k][strlen(name[k])]=same_name;
                    strcpy(final_name[f],name[k]);
                    final_name[f][strlen(final_name[f])]=' ';
                    strcat(final_name[f],number[k]);
                    f++;
                }                
            }            
        }
    }
    for(int i=0;i<f;i++)
    {
        for(int j=i+1;j<f;j++)
        {
            if(strcmp(final_name[i],final_name[j])>0)
            {
                char temp[50]={'\0'};
                strcpy(temp,final_name[i]);
                strcpy(final_name[i],final_name[j]);
                strcpy(final_name[j],temp);
            }
        }
    }
    for(int i=0;i<f;i++)
    {
        printf("%s\n",final_name[i]);
    }
    return 0;    
}