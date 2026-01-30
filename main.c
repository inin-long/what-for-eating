#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

void printWelcome() {
    const char *welcome_art[] = {
        "            __                __           ___                       ",
        "           /\\ \\              /\\ \\__      /'___\\                      ",
        " __  __  __\\ \\ \\___      __  \\ \\ ,_\\    /\\ \\__/  ___   _ __          ",
        "/\\ \\/\\ \\/\\ \\\\ \\  _ `\\  /'__`\\ \\ \\ \\/    \\ \\ ,__\\/ __`\\/\\`'__\\        ",
        "\\ \\ \\_/ \\_/ \\\\ \\ \\ \\ \\/\\ \\L\\.\\_\\ \\ \\_    \\ \\ \\_/\\ \\L\\ \\ \\ \\/         ",
        " \\ \\___x___/' \\ \\_\\ \\_\\ \\__/._\\\\ \\__\\    \\ \\_\\\\ \\____/\\ \\_\\         ",
        "  \\/__//__/    \\/_/\\/_/\\/__/\\/_/ \\/__/     \\/_/ \\/___/  \\/_/         ",
        "                                                                     ",
        "                                                                     ",
        "                          __                                         ",
        "                         /\\ \\__  __                                  ",
        "              __     __  \\ \\ ,_\\/\\_\\    ___      __                  ",
        "            /'__`\\ /'__`\\ \\ \\ \\/\\/\\ \\ /' _ `\\  /'_ `\\                ",
        "           /\\  __//\\ \\L\\.\\_\\ \\ \\_\\ \\ \\/\\ \\/\\ \\/\\ \\L\\ \\               ",
        "           \\ \\____\\ \\__/._\\\\ \\__\\\\ \\_\\ \\_\\ \\_\\ \\____ \\              ",
        "            \\/____/\\/__/\\/_/ \\/__/ \\/_/\\/_/\\/_/\\/___L\\ \\             ",
        "                                                 /\\____/             ",
        "                                                 \\_/__/              ",
        NULL
    };

    for (int i = 0; welcome_art[i] != NULL; i++) {
        printf("%s\n", welcome_art[i]);
    }
}

int main(void) {
    // Windows console UTF-8 setup
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    printWelcome();

    printf("主菜单：\n1. 随机推荐\n2. 管理食物\n3. 查看历史\n4. 按分类筛选\n5. 清空历史\n6. 退出\n");
    printf("请输入序号选择你的操作：\n");
    char choice;
    do {
        choice = getchar();
        while (getchar() != '\n');
        printf("%c ", choice);
        switch (choice) {
            case '1':
                printf("随机推荐\n");
                break;
            case '2':
                printf("管理食物\n");
                break;
            case '3':
                printf("查看历史\n");
                break;
            case '4':
                printf("按分类筛选\n");
                break;
            case '5':
                printf("清空历史\n");
                break;
            default:
                printf("请重新输入\n");
        }
    } while (choice != '6');
    printf("感谢使用！\n");
    return 0;
}
