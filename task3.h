#ifndef TASK3_H
#define TASK3_H

typedef struct {
    int id;
    char username[100];
    int age;
    char country[100];
    float price;
} Gid;

void load_elements(Gid **gids, int *count);
void display_elements(Gid **gids, int *count);
void search_elements(Gid **gids, int *count);
void add_elements(Gid **gids, int *count);
void del_elements(Gid **gids, int *count);
void change_elements(Gid **gids, int *count);
void save_elements(Gid **gids, int *count);

#endif
