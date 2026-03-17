#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int D[27]={0};
    char ch;
    char last_char='\n';
    // 在新一行CTRL+Z结束输入的方法
    while(1)
    {
        ch = getchar();
        if(ch == EOF)
        {
            if (last_char == '\n')
                break;
            else
                continue;
        }
        if(ch >= 'a' && ch <= 'z')
        {
            D[ch - 'a']++;
        }
        last_char = ch;
    }
    // 获取最大长度
    int max_length = 0;
    for (int i = 0;i<26;i++)
    {
        if (D[i] > max_length)
            max_length = D[i];
    }
    // 开始打印
    for(int i = max_length;i>0;i--)
    {
        for (int j = 0;j<26;j++)
        {
            if (D[j] >= i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    // 打印底部字母
    for (int i = 0;i<26;i++)
    {
        printf("%c", 'a'+i);
    }
    printf("\n");
}