#include <stdio.h>
#include <stdbool.h>

int n;
int path[15];      // 保存当前生成的排列
bool vis[15];      // 标记数字是否被使用过

// index 表示当前正在填第几个位置 (从 0 开始)
void dfs(int index) {
    // 递归边界：如果填满了 n 个位置，就输出
    if (index == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }

    // 核心：从小到大遍历数字 1 到 n，确保字典序
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {      // 如果数字 i 还没被用过
            path[index] = i; // 填入当前位置
            vis[i] = true;   // 标记已使用
            
            dfs(index + 1);  // 递归填下一个位置
            
            vis[i] = false;  // 回溯：恢复状态，供同层其他选择使用
        }
    }
}

int main() {
    if (scanf("%d", &n) != 1) return 0;
    
    // 初始化标记数组
    for (int i = 0; i < 15; i++) vis[i] = false;

    dfs(0);

    return 0;
}