#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[2000]={'\0'};
    fgets(str, 2000, stdin);
    // 获取小数点的起始位置和目标位置
    int start = -1,target = -1;
    int i=0;
    while(i < strlen(str) && (start == -1 || target == -1))
    {
        if(str[i] == '.')
        {
            start = i;
            i++;
            continue;
        }
        if(str[i]!='0'&& target == -1)
        {
            target = i+1;
        }
        i++;
    }
    int distance = start - target;
    if (distance < 0)
    {
        distance++;
    }
    printf("%c",str[target-1]);
    if(target < strlen(str)-1)
    {
        printf(".");
        for (int j = target; j < strlen(str); j++)
        {
            if(str[j] != '.'&& str[j] != '\n')
                printf("%c",str[j]);
        }
    }
    printf("e%d",distance);
}