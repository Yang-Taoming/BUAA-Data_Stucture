#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLINE 1024
int main()
{
    FILE *in,*out;
    char code[100]={'\0'};
    int key[26]={0};
    char line[MAXLINE]={'\0'};
    scanf("%s",code);
    for(int i=0;code[i]!='\0';i++)
    {
        key[code[i]-'a']++;
        if (key[code[i]-'a'] > 1)
        {
            key[code[i]-'a'] --;
            code[i]='\0';
            strcat(code,code+i+1);
            i--;
        }
    }
    // printf("%d",key['r'-'a']);
    // printf("%s\n",code);
    int len = strlen(code);
    for (int i = 25; i >=0; i--)
    {
        if(key[i] == 0)
        {
            code[len++] = 'a' + i;
        }
    }
    // printf("%s\n",code);
    in = fopen("encrypt.txt","r");
    out = fopen("output.txt","w");
    while(fgets(line,1000,in)!=NULL)
    {
        for(int i=0;line[i]!='\0';i++)
        {
            if(line[i] >= 'a' && line[i] <= 'z')
            {
                line[i] = code[line[i]-'a'];
            }
        }
        fputs(line,out);
        memset(line, '\0', MAXLINE);
    }

    fclose(in);
    fclose(out);
    return 0;
}