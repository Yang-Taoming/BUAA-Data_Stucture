#include <stdio.h>
#include <stdlib.h>


int field[19][19];
// int search()
// {

// }
int main(){
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            scanf("%d", &field[i][j]);
        }
    }
    // printf("棋盘状态：\n");
    // for(int i = 0; i < 19; i++)
    // {
    //     for(int j = 0; j < 19; j++)
    //     {
    //         printf("%d ", field[i][j]);
    //     }
    //     printf("\n");
    // }   
    for(int i=0;i<19;i++)
    {
        for(int j = 0; j < 19; j++)
        {
            if(field[i][j] != 0)
            {
                int color = field[i][j];
                int count_heng = 1,count_shu = 1,count_xie1 = 1,count_xie2 = 1;
                int block_heng = 0, block_shu = 0, block_xie1 = 0, block_xie2 = 0;
                // 横向
                for(int k = j + 1; k<19;k++)
                {
                    if(field[i][k] == color) count_heng++;
                    else if(field[i][k] == 0) break;
                    else{
                        block_heng++;
                        break;
                    }
                }
                for(int k = j - 1; k >= 0; k--)
                {
                    if(field[i][k] == color) count_heng++;
                    else if(field[i][k] == 0) break;
                    else{
                        block_heng++;
                        break;
                    }
                }
                if (count_heng == 4 && block_heng < 2) {
                    printf("%d:%d,%d\n", color, i+1,j+1);
                    return 0;
                }
                // 竖向
                for(int k = i + 1; k<19;k++)
                {
                    if(field[k][j] == color) count_shu++;
                    else if(field[k][j] == 0) break;
                    else{
                        block_shu++;
                        break;
                    }
                }
                for(int k = i - 1; k >= 0; k--)
                {
                    if(field[k][j] == color) count_shu++;
                    else if(field[k][j] == 0) break;
                    else{
                        block_shu++;
                        break;
                    }
                }
                if (count_shu == 4 && block_shu < 2) {
                    printf("%d:%d,%d\n", color, i+1,j+1);
                    return 0;
                }
                // 斜向1
                for(int k = 1; i+k<19 && j+k<19; k++)
                {
                    if(field[i+k][j+k] == color) count_xie1++;
                    else if(field[i+k][j+k] == 0) break;
                    else{
                        block_xie1++;
                        break;
                    }
                }
                for(int k = 1; i-k>=0 && j-k>=0; k++)
                {
                    if(field[i-k][j-k] == color) count_xie1++;
                    else if(field[i-k][j-k] == 0) break;
                    else{
                        block_xie1++;
                        break;
                    }
                }
                if (count_xie1 == 4 && block_xie1 < 2) {
                    printf("%d:%d,%d\n", color, i+1,j+1);
                    return 0;
                }
                // 斜向2
                for(int k = 1; i+k<19 && j-k>=0; k++)
                {
                    if(field[i+k][j-k] == color) count_xie2++;
                    else if(field[i+k][j-k] == 0) break;
                    else{
                        block_xie2++;
                        break;
                    }
                }
                for(int k = 1; i-k>=0 && j+k<19; k++)
                {
                    if(field[i-k][j+k] == color) count_xie2++;
                    else if(field[i-k][j+k] == 0) break;
                    else{
                        block_xie2++;
                        break;
                    }
                }
                if (count_xie2 == 4 && block_xie2 < 2) {
                    printf("%d:%d,%d\n", color, i+1,j+1);
                    return 0;
                }
            }
        }
    }
    printf("No\n");
    return 0;
}