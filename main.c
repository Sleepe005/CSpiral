#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

void printMenu(int cursePosition, bool isValN, int valN, bool isValM, int valM){
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
        if(isValN && i == 1){
            printw("   %d", valN);
        }
        if(isValM && i == 2){
            printw("   %d", valM);
        }
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
    printw("Введите число: ");

    // Читаем строку
    char buf[4];
    scanw("%3s\n", buf);  

    if(isSample(buf)){
        // Преобразуем строку в число
        *val = atoi(buf); 
        return true;
    }else{
        return false;
    }
}

void doSomething(int doing, int* valN, bool* isValN, int* valM, bool* isValM){
    switch (doing)
    {
    case 1:
        clear();
        bool getVal1 = getValue(valN);
        while (!getVal1)
        {
            clear();
            printw("Неверный форма входных данных\n");
            getVal1 = getValue(valN);
        }

        *isValN = true;
        
        break;
    
    case 2:
        clear();
        bool getVal2 = getValue(valM);
        while (!getVal2)
        {
            clear();
            printw("Неверный форма входных данных\n");
            getVal2 = getValue(valM);
        }

        *isValM = true;

        break;
    
    case 3:
    {
        clear();

        if(!*isValM || !*isValN){
            printw("Не введены размеры поля\n");
            printw("\nДля выхода вглавное меню нажмите любую кнопку\n");
            getch();
            break;
        }

        const int sizeX = *valN;
        const int sizeY = *valM;

        // spiral Array
        int **spiral = (int **)malloc(sizeX * sizeof(int *));
        for (int i = 0; i < sizeX; i++) {
            spiral[i] = (int *)malloc(sizeY * sizeof(int));
        }
        // Инициализация массива
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                spiral[i][j] = -1; // Присваиваем -1 всем элементам
            }
        }

        int x = 0, y = 0;
        int it = 0;
        spiral[x][y] = ++it;
        while(it < sizeX*sizeY){
            // Идём до упора на право
            while(y < sizeY-1 && spiral[x][y+1] == -1){
                spiral[x][y+1] = ++it;
                ++y;
            }

            // До упора в низ
            while(x < sizeX-1 && spiral[x+1][y] == -1){
                spiral[x+1][y] = ++it;
                ++x;
            }

            // До упора в лево
            while(y > 0 && spiral[x][y-1] == -1){
                spiral[x][y-1] = ++it;
                --y;
            }

            // До упора на верх
            while(x > 0 && spiral[x-1][y] == -1){
                spiral[x-1][y] = ++it;
                --x;
            }
        }
        
        for(int i = 0; i < sizeX; i++){
            for(int j = 0; j < sizeY; j++){
                printw(" %3d ", spiral[i][j]);
            }
            printw("\n");
        }

        printw("\nДля выхода вглавное меню нажмите любую кнопку\n");

        getch();
        break;
    }
    
    case 4:
    {
        clear();

        if(!*isValM || !*isValN){
            printw("Не введены размеры поля\n");
            printw("\nДля выхода вглавное меню нажмите любую кнопку\n");
            getch();
            break;
        }

        const int sizeX = *valN;
        const int sizeY = *valM;

        // spiral Array
        int **spiral = (int **)malloc(sizeX * sizeof(int *));
        for (int i = 0; i < sizeX; i++) {
            spiral[i] = (int *)malloc(sizeY * sizeof(int));
        }
        // Инициализация массива
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                spiral[i][j] = -1; // Присваиваем -1 всем элементам
            }
        }

        int x = 0, y = 0;
        int it = 0;
        spiral[x][y] = ++it;
        while(it < sizeX*sizeY){
            // До упора в низ
            while(x < sizeX-1 && spiral[x+1][y] == -1){
                spiral[x+1][y] = ++it;
                ++x;
            }

            // Идём до упора на право
            while(y < sizeY-1 && spiral[x][y+1] == -1){
                spiral[x][y+1] = ++it;
                ++y;
            }
            
            // До упора на верх
            while(x > 0 && spiral[x-1][y] == -1){
                spiral[x-1][y] = ++it;
                --x;
            }

            // До упора в лево
            while(y > 0 && spiral[x][y-1] == -1){
                spiral[x][y-1] = ++it;
                --y;
            }
        }
        
        for(int i = 0; i < sizeX; i++){
            for(int j = 0; j < sizeY; j++){
                printw(" %3d ", spiral[i][j]);
            }
            printw("\n");
        }

        printw("\nДля выхода вглавное меню нажмите любую кнопку\n");

        getch();
        
        break;
    }
        
    case 6:
    {
        clear();

        if(!*isValM || !*isValN){
            printw("Не введены размеры поля\n");
            printw("\nДля выхода вглавное меню нажмите любую кнопку\n");
            getch();
            break;
        }

        const int sizeX = *valN;
        const int sizeY = *valM;

        // spiral Array
        int **spiral = (int **)malloc(sizeX * sizeof(int *));
        for (int i = 0; i < sizeX; i++) {
            spiral[i] = (int *)malloc(sizeY * sizeof(int));
        }
        // Инициализация массива
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                spiral[i][j] = -1; // Присваиваем -1 всем элементам
            }
        }

        int x = 0, y = 0;
        int it = 0;
        spiral[x][y] = ++it;
        while(it < sizeX*sizeY){
            // Идём до упора на право
            while(y < sizeY-1 && spiral[x][y+1] == -1){
                spiral[x][y+1] = ++it;
                ++y;
            }

            // До упора в низ
            while(x < sizeX-1 && spiral[x+1][y] == -1){
                spiral[x+1][y] = ++it;
                ++x;
            }

            // До упора в лево
            while(y > 0 && spiral[x][y-1] == -1){
                spiral[x][y-1] = ++it;
                --y;
            }

            // До упора на верх
            while(x > 0 && spiral[x-1][y] == -1){
                spiral[x-1][y] = ++it;
                --x;
            }
        }
        
        for(int i = 0; i < sizeX; i++){
            for(int j = 0; j < sizeY; j++){
                printw(" %3d ", abs(spiral[i][j]-sizeX*sizeY)+1);
            }
            printw("\n");
        }

        printw("\nДля выхода вглавное меню нажмите любую кнопку\n");

        getch();
        break;
    }

    case 5:
    {
        clear();

        if(!*isValM || !*isValN){
            printw("Не введены размеры поля\n");
            printw("\nДля выхода вглавное меню нажмите любую кнопку\n");
            getch();
            break;
        }

        const int sizeX = *valN;
        const int sizeY = *valM;

        // spiral Array
        int **spiral = (int **)malloc(sizeX * sizeof(int *));
        for (int i = 0; i < sizeX; i++) {
            spiral[i] = (int *)malloc(sizeY * sizeof(int));
        }
        // Инициализация массива
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                spiral[i][j] = -1; // Присваиваем -1 всем элементам
            }
        }

        int x = 0, y = 0;
        int it = 0;
        spiral[x][y] = ++it;
        while(it < sizeX*sizeY){
            // До упора в низ
            while(x < sizeX-1 && spiral[x+1][y] == -1){
                spiral[x+1][y] = ++it;
                ++x;
            }

            // Идём до упора на право
            while(y < sizeY-1 && spiral[x][y+1] == -1){
                spiral[x][y+1] = ++it;
                ++y;
            }
            
            // До упора на верх
            while(x > 0 && spiral[x-1][y] == -1){
                spiral[x-1][y] = ++it;
                --x;
            }

            // До упора в лево
            while(y > 0 && spiral[x][y-1] == -1){
                spiral[x][y-1] = ++it;
                --y;
            }
        }
        
        for(int i = 0; i < sizeX; i++){
            for(int j = 0; j < sizeY; j++){
                printw(" %3d ", abs(spiral[i][j]-sizeX*sizeY)+1);
            }
            printw("\n");
        }

        printw("\nДля выхода вглавное меню нажмите любую кнопку\n");

        getch();
        
        break;
    }

    default:
        break;
    }
}

int main(){
    setlocale(LC_ALL, "");
    initscr();

    int key;
    bool wantExit = false;

    int cursePosition = 1;
    int valN, valM;
    bool isValN = false, isValM = false;

    while(!wantExit){
        printMenu(cursePosition, isValN, valN, isValM, valM);

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
        }else if(key == 10){
            doSomething(cursePosition, &valN, &isValN, &valM, &isValM);
        }else if(key == 49){
            cursePosition = 1;
            doSomething(cursePosition, &valN, &isValN, &valM, &isValM);
        }else if(key == 50){
            cursePosition = 2;
            doSomething(cursePosition, &valN, &isValN, &valM, &isValM);
        }else if(key == 51){
            cursePosition = 3;
            doSomething(cursePosition, &valN, &isValN, &valM, &isValM);
        }else if(key == 52){
            cursePosition = 4;
           doSomething(cursePosition, &valN, &isValN, &valM, &isValM);
        }else if(key == 53){
            cursePosition = 5;
            doSomething(cursePosition, &valN, &isValN, &valM, &isValM);
        }else if(key == 54){
            cursePosition = 6;
            doSomething(cursePosition, &valN, &isValN, &valM, &isValM);
        }else if(key == 55){
            cursePosition = 7;
            doSomething(cursePosition, &valN, &isValN, &valM, &isValM);
        }

        clear();
    }

    endwin();
    return 0;
}