#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 1024
// char tolower(char c)
// {
//     if(c >= 'A' && c <= 'Z')
//         return c + 'a' - 'A';
//     else
//         return c;
// }
void replace(char *line,char *ori,char *rep);
int main()
{
    char line[MAXLINE]={'\0'};
    FILE *in,*out;
    in = fopen("filein.txt","r");
    out = fopen("fileout.txt","w");
    char ori[100]={'\0'},rep[100]={'\0'};
    scanf("%s",ori);
    scanf("%s",rep);
    while(fgets(line,1000,in)!=NULL)
    {
        replace(line,ori,rep);
        fputs(line,out);
        memset(line, '\0', MAXLINE);
    }
    fclose(in);
    fclose(out);
    return 0;
}
void replace(char *line,char *ori,char *rep)
{
    int i,j;
    for(i=0;line[i]!='\0';i++)
    {
        for(j=0;ori[j]!='\0';j++)
        {
            if(tolower(line[i+j])!=tolower(ori[j]))
                break;
        }
        if(ori[j]=='\0')
        {
            // line[i]='\0';
            // strcat(line,rep);
            // strcat(line,line+i+j);
            int delta = strlen(rep) - strlen(ori);
            if(delta >= 0)
            {
                for(int k=strlen(line)+delta-1;k>=i+strlen(rep);k--)
                {
                    line[k] = line[k-delta];
                }
                for(int k=0;rep[k]!='\0';k++)
                {
                    line[i+k] = rep[k];
                }
            }
            else
            {
                for(int k=i+strlen(rep);k<=strlen(line);k++)
                {
                    line[k] = line[k-delta];
                }
                for(int k=0;rep[k]!='\0';k++)
                {
                    line[i+k] = rep[k];
                }
            }
            i += strlen(rep)-1;
        }
    }
}