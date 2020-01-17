#define _WIN32_WINNT 0x0500
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

void draw(char simbols[], int numbers[], int simbol_number, HDC hdc){

    int posY = 17;
    int maxNum = 0;

    for (int k = 0; k < simbol_number; k++) {
        Rectangle(hdc, 20, posY, 20 + numbers[k] * 10, posY + 14);
        if(numbers[k] > maxNum) maxNum = numbers[k];
        posY+=16;
    }
    int posX = 20;
    if(true)///SETKA
    {
        for (int i = 0; i < maxNum * 10; i+=3)
        {
            SetPixel(hdc, i + 20, posY - 2, RGB(255,0,0));
            SetPixel(hdc, i + 20, 16, RGB(255,0,0));
        }
        for (int i = 0; i <= maxNum; i++)
        {
            for (int j = posY - 2; j > 16; j-=3) SetPixel(hdc, posX + i * 10, j, RGB(255,0,0));
        }
    }///SETKA

}

int main()
{
    HWND myconsole = GetConsoleWindow();
    HDC hdc = GetDC(myconsole);
    string str, buf;
    ifstream fin;
    SetConsoleOutputCP(1251);
    fin.open("txt.txt");
    while(!fin.eof()){
        fin >> buf;
        str+= buf;
    }
    buf = "";
    fin.close();
    cout << str << endl;
    int simbol_number = 1;
    int *numbers = new int [simbol_number];
    char *simbols = new char [simbol_number];
    simbols[0] = str[0];
    numbers[0] = 1;
    bool flag;
    for (int i = 1; i < str.length(); i++) {
        flag = false;
        for (int j = 0; j < simbol_number; j++) {
            if (str[i] == simbols[j]){
                numbers[j]++;
                flag = true;
            }
        }
        if (!flag){
            simbol_number++;
            simbols[simbol_number - 1] = str[i];
            numbers[simbol_number - 1] = 1;
        }
    }
    for (int i = 0; i < simbol_number; i++) cout << simbols[i];
    cout << simbol_number;
        for (int k = 0; k < simbol_number; k++) {
        cout << simbols[k] << endl;
    }
    draw(simbols, numbers, simbol_number, hdc);
    do{
        draw(simbols, numbers, simbol_number, hdc);
    }while(getch() != 0);
    return 0;
}
