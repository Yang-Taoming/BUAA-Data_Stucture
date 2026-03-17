#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 将数组[l,r]范围内的元素循环左移
void rotate_left(int *nums, int l, int r)
{
    int temp = nums[l];
    for(int i = l; i < r; i++)
        nums[i] = nums[i+1];
    nums[r] = temp;
}

// 将数组[l,r]范围内的元素循环右移（恢复用）
void rotate_right(int *nums, int l, int r)
{
    int temp = nums[r];
    for(int i = r; i > l; i--)
        nums[i] = nums[i-1];
    nums[l] = temp;
}

void permute(int *nums, int l, int r)
{
    if (l == r)
    {
        for (int i = 0; i < r + 1; i++)
        {
            printf("%d ", nums[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            rotate_right(nums, l, i);  // 将第i个元素移到前面，其余元素右移
            permute(nums, l + 1, r);
            rotate_left(nums, l, i); // 恢复原状
        }
    }
}

int main()
{
    int num = 0;
    scanf("%d",&num);
    int nums[100]={0};
    for (int i = 0; i < num; i++)
    {
        nums[i] = i+1;
    }
    permute(nums, 0, num - 1);
    return 0;
}