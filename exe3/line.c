#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h> 
struct node
{
    int x_start;
    int y_start;
    int x_end;
    int y_end;
    struct node *link;
};
int main()
{
    int n;
    scanf("%d",&n);
    struct node *list= NULL,*p,*q;
    for(int i=0;i<n;i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d %d %d %d",&p->x_start,&p->y_start,&p->x_end,&p->y_end);
        p->link = NULL;
        if(list == NULL)
        {
            list = p;
        }
        else
        {
            q->link = p;
        }
        q = p;
    }
    int max_len = 1,max_x_start = 0,max_y_start = 0;
    for(p=list;p!=NULL ;p=p->link)
    {
        int x_start = p->x_start;
        int y_start = p->y_start;
        int x_end = p->x_end;
        int y_end = p->y_end;
        int len = 1;
        for(q=list;q!=NULL ;q=q->link)
        {
            if(q->x_start == x_end && q->y_start == y_end)
            {
                x_end = q->x_end;
                y_end = q->y_end;
                len++;
                q = list;
            }
            else if(q->y_end == y_start && q->x_end == x_start)
            {
                x_start = q->x_start;
                y_start = q->y_start;
                len++;
                q = list;
            }
        }
        if(len > max_len)
        {
            max_len = len;
            max_x_start = x_start;
            max_y_start = y_start;
        }
    }
    printf("%d %d %d",max_len,max_x_start,max_y_start);
}