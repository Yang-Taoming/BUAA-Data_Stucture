#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int get_type(int type);
int main()
{
    char ch;
    char last_char = 0;
    char last_last_char = 0;
    char str[10000]={0};
    int l_type = 3;
    int c_type = 3;
    int index = 0; 
    while(1)
    {
        ch = getchar();
        if(ch == EOF)
        {            
            break;
        }
        if(last_char == '-')
        {
            c_type = get_type(ch);
            if(c_type == l_type && ch > last_last_char)
            {
                for(int i = last_last_char + 1;i<ch;i++)
                {
                    str[index++] = i;
                }
            }
            else
            {
                str[index++] = last_char;
            }
        }
        else if(last_char != 0)
        {
            str[index++] = last_char;
        }

        last_last_char = last_char;
        last_char = ch;
        l_type = get_type(last_last_char);
    }
    printf("%s\n", str);
}
int get_type(int type)
{
    if(type >= 'a' && type <= 'z')
        return 0;
    else if(type >= 'A' && type <= 'Z')
        return 1;
    else if(type >= '0' && type <= '9')
        return 2;
    else
        return 3;
}