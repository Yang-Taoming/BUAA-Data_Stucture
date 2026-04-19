#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h> 
struct node
{
    int location;
    int space;
    struct node *link;
};
int main()
{
    int n;
    int need_space = 0;
    scanf("%d",&n);
    struct node *list= NULL,*p,*q,*p0,*flag=NULL;
    for(int i=0;i<n;i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d %d",&p->location,&p->space);
        if(list == NULL)
        {
            list = p;
            p->link = p;
        }
        else if(p->location < list->location)
        {
            p->link = list;
            for(p0=list;p0->link!=list;p0=p0->link);
            p0->link = p;
            list = p;
        }
        else
        {
            struct node *curr = list;
            while (curr->link != list && curr->link->location < p->location) {
                curr = curr->link;
            }
            p->link = curr->link;
            curr->link = p;
        }
    }
    scanf("%d",&need_space);
    while(need_space != -1)
    {
        flag = NULL;
        int best_suitted = -1;
        p = list;
        do
        {
            if(p->space >= need_space)
            {
                int cha = p->space - need_space;
                if(best_suitted == -1 || cha < best_suitted)
                {
                    best_suitted = cha;
                    flag = p;
                }
            }
            p = p->link;
        }while(p!=list);
        if(flag != NULL)
        {
            flag->space -= need_space;
            if(flag->space == 0)
            {
                if (flag == list)
                {
                    if(flag->link == list)
                    {
                        free(flag);
                        list = NULL;
                    }
                    else
                    {
                    list = flag->link;
                    for(p=list;p->link!=flag;p=p->link);
                    p->link = flag->link;
                    free(flag);
                    }
                }
                else
                {
                for(p=list;p->link!=flag;p=p->link);
                
                p->link = flag->link;
                list = flag->link;
                free(flag);
                    
                }
            }   
            
            else 
            {
                list = flag;
            }
        }
        scanf("%d",&need_space);
    }
    if (list !=NULL)
    {
        p = list;
        do
        {
            printf("%d %d\n",p->location,p->space);
            p = p->link;
        } while (p!=list);
        
    }
    return 0;
}