#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINE 1024

struct node
{
    char word[100];
    int count;
    struct node *link;
};

int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    if (in == NULL)
    {
        return 0;
    }

    struct node *list = NULL, *p, *q, *p0;
    char line[MAXLINE] = {'\0'};
    char temp[100] = {'\0'};
    int len = 0;

    while (fgets(line, MAXLINE, in) != NULL)
    {
        for (int i = 0; line[i] != '\0'; i++)
        {
            if (isalpha(line[i]))
            {
                temp[len++] = tolower(line[i]);
            }
            else
            {
                if (len > 0)
                {
                    temp[len] = '\0';
                    int found = 0;
                    
                    if (list == NULL)
                    {
                        p = (struct node *)malloc(sizeof(struct node));
                        strcpy(p->word, temp);
                        p->count = 1;
                        p->link = NULL;
                        list = p;
                    }
                    else
                    {
                        p0 = NULL;
                        q = list;
                        while (q != NULL)
                        {
                            int cmp = strcmp(temp, q->word);
                            if (cmp == 0)
                            {
                                q->count++;
                                found = 1;
                                break;
                            }
                            else if (cmp < 0)
                            {
                                break;
                            }
                            p0 = q;
                            q = q->link;
                        }
                        
                        if (found == 0)
                        {
                            p = (struct node *)malloc(sizeof(struct node));
                            strcpy(p->word, temp);
                            p->count = 1;
                            p->link = q;
                            
                            if (p0 == NULL)
                            {
                                list = p;
                            }
                            else
                            {
                                p0->link = p;
                            }
                        }
                    }
                    len = 0;
                    memset(temp, '\0', sizeof(temp));
                }
            }
        }
    }
    
    p = list;
    while (p != NULL)
    {
        printf("%s %d\n", p->word, p->count);
        p = p->link;
    }

    fclose(in);
    return 0;
}