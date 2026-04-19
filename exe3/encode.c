#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h> 
#define MAXLINE 1024
struct node
{
    char origin;
    struct node *link;
};
int main()
{
    struct node *list=NULL,*q,*p0;

    FILE *in,*out;
    in = fopen("in.txt","r");
    out = fopen("in_crpyt.txt","w");
    char mima[100]={'\0'};
    int count[95] = {0};
    fgets(mima,100,stdin);
    mima[strcspn(mima, "\n")] = '\0';
    for(int i =0;mima[i]!='\0';i++)
    {
        char ch = mima[i];
        
        if(count[ch - ' '] > 0)
        {
            continue;
        }
        count[ch - ' ']++;
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->origin = ch;
        p->link = NULL;
        if(list == NULL)
        {
            list = p;
            q = p;
        }
        else
        {
            q->link = p;
            q=p;
        }
    }
    if(list != NULL)
    {
        q->link = list;
    }
    for(int i = 0; i < 95; i++)
    {
        if(count[i] > 0)
        {
            continue;
        }
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->origin = ' ' + i;
        p->link = NULL;
        if(list == NULL)
        {
            list = p;
            q = p;
        }
        else
        {
            q->link = p;
            q = p;
        }
    }
    int init_num = list->origin;
    q->link = list;
    p0 = q;
    q = list;
    for(;q->link!=q;)
    {
        int num = q->origin;
        p0->link = q->link;
        free(q);
        q=p0->link;
        for(int i = 1; i<num-1;i++)
        {
            q=q->link;
        }
        p0 = q;
        q=q->link;
        count[num-' ']=q->origin;
    }
    count[q->origin - ' '] = init_num;
    char line[MAXLINE]={'\0'};
    while(fgets(line,MAXLINE,in)!=NULL)
    {
        for(int i=0;line[i]!='\0';i++)
        {
            if(line[i] >= ' ' && line[i] <= '~')
            {
                line[i] = count[line[i]-' '];
            }
        }
        fputs(line,out);
        memset(line, '\0', MAXLINE);
    }
    fclose(in);
    fclose(out);
    return 0;
}