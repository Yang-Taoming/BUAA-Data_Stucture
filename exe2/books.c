#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h> 
#define MAXLINE 1024
// void swap(char *p1[],char *p2[])
// {
//     char *temp[]=*p1;
//     *p1=*p2;
//     *p2=temp;
// }
int main()
{
    char line[MAXLINE]={'\0'};
    FILE *in,*out;
    in = fopen("books.txt","r");
    out =fopen("ordered.txt","w");
    char book[500][50]={'\0'},author[500][20]={'\0'},press[500][30]={'\0'},year[500][10]={'\0'};
    //先排序好
    // 1,读取文件
    int tot=0;
    while(fgets(line,1000,in)!=NULL)
    {
        int i=0;
        for(int j=0;line[i]!=' ';i++,j++)
        {
            book[tot][j] = line[i];
        }
        i++;
        for(int j=0;line[i]!=' ';i++,j++)
        {
            author[tot][j] = line[i];
        }
        i++;
        for(int j=0;line[i]!=' ';i++,j++)
        {
            press[tot][j] = line[i];
        }
        i++;
        for(int j=0;line[i]!='\n' && line[i]!='\0';i++,j++)
        {
            year[tot][j] = line[i];
        }
        tot++;
        //读取后就排序
        for(int k=tot-1;k>0;k--)
        {
            if(strcmp(book[k],book[k-1])<0)
            {
                char temp[50]={'\0'};
                memcpy(temp,book[k],50);
                memcpy(book[k],book[k-1],50);
                memcpy(book[k-1],temp,50);
                char temp2[20]={'\0'};
                memcpy(temp2,author[k],20);
                memcpy(author[k],author[k-1],20);
                memcpy(author[k-1],temp2,20);
                char temp3[30]={'\0'};
                memcpy(temp3,press[k],30);
                memcpy(press[k],press[k-1],30);
                memcpy(press[k-1],temp3,30);
                char temp4[10]={'\0'};
                memcpy(temp4,year[k],10);
                memcpy(year[k],year[k-1],10);
                memcpy(year[k-1],temp4,10);
            }
        }
        memset(line,'\0',1000);
    }

    // for(int i=0;i<tot;i++)
    // {
    //     printf("%s %s %s %s\n",book[i],author[i],press[i],year[i]);
    //     // printf("%s\n",author[i]);
    // }

    // 2,设置输入功能
    char input;
    while((input=getchar())!='0')
    {
        getchar();
        // 处理输入
        if(input=='1')
        {
            // 处理选项1
            char luru[MAXLINE]={'\0'};
            fgets(luru,1000,stdin);
            int i=0;
            for(int j=0;luru[i]!=' ';i++,j++)
            {
                book[tot][j] = luru[i];
            }
            i++;
            for(int j=0;luru[i]!=' ';i++,j++)
            {
                author[tot][j] = luru[i];
            }
            i++;
            for(int j=0;luru[i]!=' ';i++,j++)
            {
                press[tot][j] = luru[i];
            }
            i++;
            for(int j=0;luru[i]!='\n' && luru[i]!='\0';i++,j++)
            {
                year[tot][j] = luru[i];
            }
            tot++;
            // 插入排序
            for(int k=tot-1;k>0;k--)
            {
                if(strcmp(book[k],book[k-1])<0)
                {
                    char temp[50]={'\0'};
                    memcpy(temp,book[k],50);
                    memcpy(book[k],book[k-1],50);
                    memcpy(book[k-1],temp,50);
                    char temp2[20]={'\0'};
                    memcpy(temp2,author[k],20);
                    memcpy(author[k],author[k-1],20);
                    memcpy(author[k-1],temp2,20);
                    char temp3[30]={'\0'};
                    memcpy(temp3,press[k],30);
                    memcpy(press[k],press[k-1],30);
                    memcpy(press[k-1],temp3,30);
                    char temp4[10]={'\0'};
                    memcpy(temp4,year[k],10);
                    memcpy(year[k],year[k-1],10);
                    memcpy(year[k-1],temp4,10);
                }
            }
        }
        else if(input=='2')
        {
            // 处理选项2，查找操作
            char chazhao[MAXLINE]={'\0'};
            fgets(chazhao,1000,stdin);
            for(int i=0;i<tot;i++)
            {
                for(int j=0;j<strlen(book[i]);j++)
                {
                    int s=0;
                    for(;s<strlen(chazhao)-1;s++)
                    {
                        if(book[i][j+s]!=chazhao[s])
                        {
                            break;
                        }
                    }
                    if(chazhao[s]=='\n')
                    {
                        for(int k=0;k<50;k++)
                        {
                            if(book[i][k]=='\0')
                            {
                                printf(" ");
                                continue;
                            }
                            printf("%c",book[i][k]);
                        }
                        for(int k=0;k<20;k++)
                        {
                            if(author[i][k]=='\0')
                            {
                                printf(" ");
                                continue;
                            }
                            printf("%c",author[i][k]);
                        }
                        for(int k=0;k<30;k++)
                        {
                            if(press[i][k]=='\0')
                            {
                                printf(" ");
                                continue;
                            }
                            printf("%c",press[i][k]);
                        }
                        for(int k=0;k<10;k++)
                        {
                            if(year[i][k]=='\0')
                            {
                                printf(" ");
                                continue;
                            }
                            printf("%c",year[i][k]);
                        }
                        printf("\n");
                        break;
                    }
                }
            }
        }
        else
        {
            // 处理选项3,删除操作
            char chazhao[MAXLINE]={'\0'};
            fgets(chazhao,1000,stdin);
            for(int i=0;i<tot;i++)
            {
                for(int j=0;j<strlen(book[i]);j++)
                {
                    int s=0;
                    for(;s<strlen(chazhao)-1;s++)
                    {
                        if((book[i][j+s])!=chazhao[s])
                        {
                            break;
                        }
                    }
                    if(chazhao[s]=='\n')
                    {
                        for(int k=i+1;k<tot;k++)
                        {
                            memcpy(book[k-1],book[k],50);
                            memcpy(author[k-1],author[k],20);
                            memcpy(press[k-1],press[k],30);
                            memcpy(year[k-1],year[k],10);
                        }
                        tot--;
                        i--;
                        break;
                    }
                }
            }
        }
        //处理换行符        
    }
    for(int i=0;i<tot;i++)
    {
        fputs(book[i],out);
        for(int k=strlen(book[i]);k<50;k++)
        {
            fputs(" ",out);
        }
        fputs(author[i],out);
        for(int k=strlen(author[i]);k<20;k++)
        {
            fputs(" ",out);
        }
        fputs(press[i],out);
        for(int k=strlen(press[i]);k<30;k++)
        {
            fputs(" ",out);
        }
        fputs(year[i],out);
        for(int k=strlen(year[i]);k<10;k++)
        {
            fputs(" ",out);
        }
        if(i!=tot-1)
            fputs("\n",out);
    }
    fclose(in);
    fclose(out);
}