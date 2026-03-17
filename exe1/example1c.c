#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int apply(int a, int b, char op)
{
    if(op == '+')
        return a+b;
    else if(op == '-')
        return a-b;
    else if(op == '/')
        return a/b;
    else
        return a*b;
}
int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else
        return 2;
}
int main()
{
    // 初始化两个栈，分别存储数字和运算符,str存储运算符，nums存储数字,str1存储输入的字符串
    int nums[2000]= {0};
    char str[2000]= {"\0"};
    int num_top = -1;
    int op_top = -1;

    char str1[2000]={'\0'};
    // char str1[200]='\0';
    fgets(str1, 2000, stdin);
    // 去除空格，然后进行栈堆放
    int i = 0;
    while(str1[i]!= '=' )
    {
        if(str1[i]==' ')
        {
            i++;
            continue;
        }
        if(str1[i]>='0' && str1[i]<='9')
        {
            int num = 0;
            while(i<strlen(str1) && str1[i]>='0' && str1[i]<='9')
            {
                num = num*10 + (str1[i]-'0');
                i++;
            }
            nums[++num_top] = num;
        }
        else
        {
            while(op_top>=0 && priority(str1[i]) <= priority(str[op_top]))
            {
                char op = str[op_top--];
                int b = nums[num_top--];
                int a = nums[num_top--];
                nums[++num_top] = apply(a, b, op);
            }
            str[++op_top] = str1[i];
            i++;
        }
        
    }
    while (op_top >= 0)
    {
        char op = str[op_top--];
        int b = nums[num_top--];
        int a = nums[num_top--];
        nums[++num_top] = apply(a, b, op);
    }
    printf("%d\n", nums[num_top]);
}