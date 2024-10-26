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
        }

        clear();
    }

    clear();
    printw("Всё");
    getch();

    endwin();
    return 0;
}