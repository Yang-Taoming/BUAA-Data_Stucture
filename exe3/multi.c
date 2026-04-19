#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h> 
struct node
{
    int xishu;
    int cishu;
    struct node *link;
};
int main()
{
    int a,n;
    char c;
    struct node *list=NULL,*list2=NULL,*p,*q,*p0=NULL,*list0=NULL,*q0,*r0;
    do
    {
        scanf("%d%d%c",&a,&n,&c);
        p = (struct node *)malloc(sizeof(struct node));
        p->xishu = a;
        p->cishu = n;
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
    while(c != '\n');
    do
    {
        scanf("%d%d%c",&a,&n,&c);
        p = (struct node *)malloc(sizeof(struct node));
        p->xishu = a;
        p->cishu = n;
        p->link = NULL;
        if(list2 == NULL)
        {
            list2 = p;
        }
        else
        {
            q->link = p;
        }
        q = p;
    } while (c!= '\n');
    for(p=list;p!=NULL;p=p->link)
    {
        for(q=list2;q!=NULL;q=q->link)
        {
            p0 = (struct node *)malloc(sizeof(struct node));
            p0->xishu = p->xishu * q->xishu;
            p0->cishu = p->cishu + q->cishu;
            p0->link = NULL;
            if(list0 == NULL)
            {
                list0 = p0;
            }
            else
            {
                for(r0=q0=list0;r0!=NULL;q0=r0,r0=r0->link)
                {
                    if(r0->cishu == p0->cishu)
                    {
                        r0->xishu += p0->xishu;
                        free(p0);
                        break;
                    }
                    else if(p0->cishu >r0->cishu)
                    {
                        p0->link = r0;
                        if(r0 == list0)
                        {
                            list0 = p0;
                        }
                        else
                        {
                            q0->link = p0;
                        }
                        break; 
                    }
                    else if(r0->link == NULL)
                    {
                        r0->link = p0;
                        break;
                    }
                }
            }
        }
    }
    for(p=list0;p!=NULL;p=p->link)
    {
        if(p->xishu != 0)
        {
            printf("%d %d ",p->xishu,p->cishu);
        }
    }
    return 0;
}