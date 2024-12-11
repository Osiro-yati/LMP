#include <stdio.h>
#include <stdlib.h>
#include "task3.h"

int main() {
    Gid *gids = NULL;
    int count = 0;
    load_elements(&gids, &count);

    int choice;
    do {
        printf("Меню:\n");
        printf("1. Вывести все путевки\n");
        printf("2. Добавить путевку\n");
        printf("3. Удалить путевку\n");
        printf("4. Изменить путевку\n");
        printf("5. Найти путевку\n");
        printf("6. Exit\n");
        printf("Введите цифру меню: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_elements(gids, count);
                break;
            case 2:
                add_elements(&gids, &count);
                break;
            case 3:
                del_elements(gids, &count);
                break;
            case 4:
                change_elements(gids, count);
                break;
            case 5:
                search_elements(gids, count);
                break;
            case 6:
                break;
            default:
                printf("Неверный ввод. Попробуйте ещё раз\n");
        }
    } while (choice != 6);

    free(gids);
    return 0;
}