#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

const char* name_of(int x) {
    switch (x) {
        case 0: return "石头";   // rock
        case 1: return "布";     // paper
        case 2: return "剪刀";   // scissors
        default: return "未知";
    }
}

int main(void) {
    char buf[100];
    int user, comp;
    time_t start_time, current_time;

    srand((unsigned)time(NULL));

    printf("=== 猜拳小游戏（石头/布/剪刀） ===\n");
    printf("规则：输入 0(石头), 1(布), 2(剪刀)。\n");
    printf("你需要在 10 秒内赢一次，否则游戏失败退出。输入 q 可提前退出。\n\n");

    /* 记录开始时间 */
    start_time = time(NULL);

    while (1) {
        /* 检查时间是否超过10秒 */
        current_time = time(NULL);
        if (difftime(current_time, start_time) >= 10.0) {
            puts("时间到！你未能在10秒内获胜，游戏结束！");
            return 0;
        }

        printf("请出拳 (0/1/2 或 q): ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            puts("读取输入失败，退出。");
            return 1;
        }

        buf[strcspn(buf, "\r\n")] = '\0';

        if (buf[0] == 'q' || buf[0] == 'Q') {
            puts("已退出游戏。再见！");
            return 0;
        }

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

        if ((user == 0 && comp == 2) ||
            (user == 1 && comp == 0) ||
            (user == 2 && comp == 1)) {
            puts("你赢了！游戏结束。恭喜！");
            return 0;
        } else {
            puts("你输了，继续加油！\n");
        }
    }

    return 0;
}