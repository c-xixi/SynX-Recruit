#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char* name_of(int x) {
    switch (x) {
        case 0: return "石头";   
        case 1: return "布";     
        case 2: return "剪刀"; 
        default: return "未知";
    }
}

int main(void) {
    char buf[100];
    int user, comp;

    /* 初始化随机数种子 */
    srand((unsigned)time(NULL));

    printf("=== 猜拳小游戏（石头/布/剪刀） ===\n");
    printf("规则：输入 0(石头), 1(布), 2(剪刀)。玩家赢一次后游戏结束。输入 q 退出。\n\n");

    while (1) {
        printf("请出拳 (0/1/2 或 q): ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* 读取失败，直接退出 */
            puts("读取输入失败，退出。");
            return 1;
        }

        /* 去掉末尾换行 */
        buf[strcspn(buf, "\r\n")] = '\0';

        if (buf[0] == 'q' || buf[0] == 'Q') {
            puts("已退出游戏。再见！");
            return 0;
        }

        /* 尝试转换为整数 */
        char *endptr;
        long val = strtol(buf, &endptr, 10);
        if (endptr == buf || *endptr != '\0') {
            puts("无效输入，请输入 0、1、2 或 q。\n");
            continue;
        }

        if (val < 0 || val > 2) {
            puts("无效选择，请输入 0、1 或 2。\n");
            continue;
        }

        user = (int)val;
        comp = rand() % 3;

        printf("你：%s    电脑：%s\n", name_of(user), name_of(comp));

        if (user == comp) {
            puts("平局，继续出拳。\n");
            continue;
        }

        /* 玩家获胜的三种情况 */
        if ((user == 0 && comp == 2) ||
            (user == 1 && comp == 0) ||
            (user == 2 && comp == 1)) {
            puts("你赢了！游戏结束。恭喜！");
            return 0; /* 赢一次后即退出 */
        } else {
            puts("你输了，继续加油！\n");
        }
    }

    return 0;
}
