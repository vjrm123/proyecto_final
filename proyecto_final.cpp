#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;


#define TECLA_ARRIBA 72
#define TECLA_IZQUIERDA 75
#define TECLA_DERECHA 77
#define TECLA_ABAJO 80

void gotoxy(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);
}

void ocultar_cursor(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 2;
    cursor.bVisible = FALSE;

    SetConsoleCursorInfo(hCon,&cursor);
}

void pintar_limites(){
    for (int i=2 ;i<78;++i){
        gotoxy(i ,3 ); printf("%c",205);
        gotoxy(i,33); printf("%c",205);
    }

    for(int i=4; i<33; i++){
        gotoxy(2,i); printf("%c",186);
        gotoxy(77,i); printf("%c",186);
    }

    gotoxy(2,3); printf("%c",201);
    gotoxy(2,33); printf("%c", 200);
    gotoxy(77,3);printf("%c",187);
    gotoxy(77,33);printf("%c",188);
}


int main(){

    ocultar_cursor();
    pintar_limites();

    
    return 0;
}