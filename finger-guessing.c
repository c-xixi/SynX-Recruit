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
    int player_wins = 0, computer_wins = 0;

    srand((unsigned)time(NULL));

    printf("=== 猜拳小游戏（石头/布/剪刀） ===\\n");
    printf("规则：输入 0(石头), 1(布), 2(剪刀)。平局不计入胜负，采用三局两胜制。输入 q 退出。\\n\\n");

    while (player_wins < 2 && computer_wins < 2) {
        printf("请出拳 (0/1/2 或 q): ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            puts("读取输入失败，退出。");
            return 1;
        }

        buf[strcspn(buf, "\\r\\n")] = '\\0';

        if (buf[0] == 'q' || buf[0] == 'Q') {
            puts("已退出游戏。再见！");
            return 0;
        }

        char *endptr;
        long val = strtol(buf, &endptr, 10);
        if (endptr == buf || *endptr != '\\0') {
            puts("无效输入，请输入 0、1、2 或 q。\\n");
            continue;
        }

        if (val < 0 || val > 2) {
            puts("无效选择，请输入 0、1 或 2。\\n");
            continue;
        }

        user = (int)val;
        comp = rand() % 3;

        printf("你：%s    电脑：%s\\n", name_of(user), name_of(comp));

        if (user == comp) {
            puts("平局，不计入胜负。\\n");
            continue;
        }

        if ((user == 0 && comp == 2) ||
            (user == 1 && comp == 0) ||
            (user == 2 && comp == 1)) {
            player_wins++;
            printf("你赢了这一局！当前比分：你 %d - %d 电脑\\n\\n", player_wins, computer_wins);
        } else {
            computer_wins++;
            printf("你输了这一局！当前比分：你 %d - %d 电脑\\n\\n", player_wins, computer_wins);
        }
    }

    if (player_wins == 2)
        puts("恭喜你！你以两胜获得最终胜利！");
    else
        puts("很遗憾，电脑以两胜获胜，下次加油！");

    return 0;
}
