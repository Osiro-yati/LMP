#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"

#define FILENAME "gids.txt"

void load_elements(Gid **gids, int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        *count = 0;
        return;
    }
    *count = 0;
    *gids = NULL;
    Gid temp;

    while (fscanf(file, "%d %s %d %s %f", &temp.id, &temp.username, &temp.age, &temp.country, &temp.price) == 4) {
        *gids = realloc(*gids, sizeof(Gid) * (*count + 1));
        (*gids)[*count] = temp;
        (*count)++;
    }

    fclose(file);
}

void save_elements(Gid *gids, int count) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) return;

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %d %s %.2f\n", gids[i].id, gids[i].username, gids[i].age, gids[i].country, gids[i].price);
    }

    fclose(file);
}

void display_products(Gid *gids, int count) {
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Имя: %s, Возраст: %d, Страна путевки: %s, Цена путевки: %.2f\n", gids[i].id, gids[i].username, gids[i].age, gids[i].country, gids[i].price);
    }
}

void add_elements(Gid **gids, int *count) {
    *gids = realloc(*gids, sizeof(Gid) * (*count + 1));
    printf("Введите ID путевки: ");
    scanf("%d", &(*gids)[*count].id);
    printf("Введите имя покупателя: ");
    scanf("%s", &(*gids)[*count].username);
    printf("Введите возраст покупателя: ");
    scanf("%d", (*gids)[*count].age);
    printf("Введите страну путевки: ");
    scanf("%s", &(*gids)[*count].country);
    printf("Введите цену путевки: ");
    scanf("%f", &(*gids)[*count].price);
    (*count)++;
    save_elements(*gids, *count);
}

void del_elements(Gid *gids, int *count) {
    int id;
    printf("Введите ID путевки для её удаления: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (gids[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                gids[j] = gids[j + 1];
            }
            (*count)--;
            gids = realloc(gids, sizeof(Gid) * (*count));
            save_elements(gids, *count);
            return;
        }
    }
    printf("Путевка не найдена.\n");
}

void change_elements(Gid *gids, int count) {
    int id;
    printf("Введите ID путевки для её изменения: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (gids[i].id == id) {
            printf("Введите имя покупателя: ");
            scanf("%s", gids[i].username);
            printf("Введите возраст покупателя: ");
            scanf("%d", gids[i].age);
            printf("Введите страну путевки: ");
            scanf("%s", gids[i].country);
            printf("Введите новую цену: ");
            scanf("%f", &gids[i].price);
            save_elements(gids, count);
            return;
        }
    }
    printf("Путевка не найдена.\n");
}

void search_elements(Gid *gids, int count) {
    char username[100];
    int age;
    printf("Введите имя покупателя для поиска: ");
    scanf("%s", username);
    printf("Введите возраст покупателя для поиска: ");
    scanf("%d", age);
    for (int i = 0; i < count; i++) {
        if (strcmp(gids[i].username, username) == 0 && gids[i].age == age) {
            printf("Нашли: ID: %d, Имя: %s, Возраст: %d, Страна: %s, Цена: %.2f\n", gids[i].id, gids[i].username, gids[i].age, gids[i].country, gids[i].price);
            return;
        }
    }
    printf("Не нашли такой путевки.\n");
}