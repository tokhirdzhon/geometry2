#include <ctype.h>
#include <stdio.h>
#include <string.h>

void delete (char str[128], int n)
{
    for (int i = n; i < strlen(str); i++) {
        str[i] = str[i + 1];
    }
}

int main()
{
    char figure[64] = "circle";
    char input[128], name[64];
    fgets(input, 128, stdin);
    input[strlen(input) - 1] = '\0';
    for (int i = 0; i < 128; i++) {
        input[i] = tolower(input[i]);
    }
    int test = 1;
    // Удаление лишних пробелов
    for (int j = 0, i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            if (!(((input[i - 1] == ',') && isdigit(input[i + 1])) ||
                  (isdigit(input[i - 1]) && isdigit(input[i + 1])))) {
                delete (input, i--);
            }
        }
        else if (isalpha(input[i]) && test) {
            name[j++] = input[i];
            name[j] = '\0';
        }
        else {
            test = 0;
        }
    }

    // Проверка названия фигуры
    if (strcmp(name, figure)) {
        printf("Error: такой фигуры не существует");
    }
    else {
        if ((input[strlen(name)] != '(') || (input[strlen(input) - 1] != ')')) {
            printf("Error: ошибка в синтаксисе");
            return 0;
        }

        int comma = 0, space = 0;
        for (int i = 0; i < strlen(input); i++) {
            if ((input[i] == '.') && (!isdigit(input[i - 1]) || !isdigit(input[i + 1]))) {
                printf("Error: ошибка в синтаксисе");
                return 0;
            }
            if (input[i] == ',') {
                comma++;
            }
            if (input[i] == ' ') {
                space++;
            }
        }
        if ((comma != 1) || (space != 2)) {
            printf("Error: invalid circle");
            return 0;
        }

        int arg = 0;
        // Проверка на правильность аргументов
        for (int i = strlen(name) + 1; i < strlen(input) - 1; i++) {
            if (isdigit(input[i])) {
                arg++;
                for (int j = i; isdigit(input[j]); j++, i++)
                    ;
                if ((arg == 1) && (input[i] != ' ')) {
                    printf("Error: invalid circle");
                    return 0;
                }
            }
        }
        puts(input);
    }

    return 0;
}