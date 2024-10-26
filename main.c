#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void printMenu(int cursePosition){
    char menu[7][75] = {
        "1. Ввод N",
        "2. Ввод M",
        "3. С наружи внутрь по часовой",
        "4. С наружи внутрь против часовой",
        "5. Из нутри наружу по часовой",
        "6. Из нутри наружу против часовой",
        "7. Выход (esc x2)"
    };

    for(int i = 1; i <= 7; i++){
        printw("%s", menu[i-1]);
        if(i == cursePosition){
            printw("    <--");
        }
        printw("\n");
    }
}

bool isSample(char val[4]){
    bool sample = true;

    // Проверяем, что число двухзначное
    if(strlen(val) > 2){
        sample = false;
    }

    // Проверяем, что строка содержит только цифры
    for(int i = 0; i < strlen(val); i++){
        if(!isdigit(val[i])){
            sample = false;
        }
    }

    return sample;
}

bool getValue(int* val){
    // Читаем строку
    char buf[4];
    scanw("%3s", buf);  

    if(isSample(buf)){
        // Преобразуем строку в число
        *val = atoi(buf); 
        return true;
    }else{
        return false;
    }
}

int main(){
    setlocale(LC_ALL, "");
    initscr();

    int key;
    bool wantExit = false;

    int cursePosition = 1;

    while(!wantExit){
        printMenu(cursePosition);

        key = getch();
        if(key == 27){
            key = getch();
            if(key == 91){
                key = getch();
                if(key == 65){
                    cursePosition--;
                    if(cursePosition < 1){
                        cursePosition = 7;
                    }
                }
                if(key == 66){
                    cursePosition++;
                    if(cursePosition > 7){
                        cursePosition = 1;
                    }
                }
            }
            if (key == 27){
                wantExit = true;
            }
        }else if(key == 49){
            cursePosition = 1;
        }else if(key == 50){
            cursePosition = 2;
        }else if(key == 51){
            cursePosition = 3;
        }else if(key == 52){
            cursePosition = 4;
        }else if(key == 53){
            cursePosition = 5;
        }else if(key == 54){
            cursePosition = 6;
        }else if(key == 55){
            cursePosition = 7;
        }

        clear();
    }

    clear();
    printw("Всё");
    getch();

    endwin();
    return 0;
}