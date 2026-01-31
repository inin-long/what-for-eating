#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif
#define MAX_NAME_LENGTH 50
#define DATA_FILE "data.txt"
#define MAX_FOODS 1000
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
enum Category{
    CHINESE,
    FAST,
    WESTERN,
    JAPANESE,
    KOREAN,
    SNACK,
    OTHERS,
};
typedef struct  {
    char name[MAX_NAME_LENGTH];
    enum Category category;
    float spicy_level;
}Food;
Food foods[MAX_FOODS];
int food_count = 0;
 void random_recommend() {
     if (food_count<=0) {
         printf("出错啦:( 请先添加食物\n");
         return;
     }
     int random_number = rand() % food_count;
     Food food = foods[random_number];
     printf("%s %.1f\n", food.name,food.spicy_level);
 }
void load_data () {
    FILE *fp;
    fp = fopen (DATA_FILE, "r");
    int food_flag = 0;
    if (fp != NULL) {
       while (food_count<MAX_FOODS){
            Food food;
            food_flag=fscanf(fp, "%49[^|]|%d|%f\n", food.name,(int*)&food.category, &food.spicy_level);

           if (food_flag >0) {
               printf("%s %d %.1f\n",food.name,food.category,food.spicy_level);
               foods[food_count]=food;
               food_count++;
           }else {
               break;
           }
        }
    }
}



int main(void) {
    // Windows console UTF-8 setup
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
     srand((unsigned int)time(NULL));
    printWelcome();
    load_data ();
    printf("主菜单：\n1. 随机推荐\n2. 管理食物\n3. 查看历史\n4. 按分类筛选\n5. 清空历史\n6. 退出\n");
    printf("请输入序号选择你的操作：\n");
    char choice;
    do {
        choice = getchar();
        while (getchar() != '\n');
        printf("%c ", choice);
        switch (choice) {
            case '1':
                random_recommend();
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
