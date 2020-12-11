#ifndef _THIS_IS_INTERPRETER_CPP
#define _THIS_IS_INTERPRETER_CPP

#include <cstdio>
#include <windows.h>
#include <wingdi.h>
#include <string>
#include "drawDot.hpp"
#include "../parser/parser.cpp"

using namespace std;
HDC hdc;
string filename = "E:\\clionData\\learnCpp\\interpreter\\testFile\\draw4.txt";


LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch (Message)
    {
        case WM_DESTROY:
            ReleaseDC(hwnd, hdc);
            PostQuitMessage(0);
            return 0;
        case WM_PAINT:
        {
            PAINTSTRUCT paint;
            BeginPaint(hwnd, &paint);
//            parser(filename);
            EndPaint(hwnd, &paint);
        }
        default:
            return DefWindowProc(hwnd, Message, wParam, lParam);
    }
}

int registerWindow(HINSTANCE hInst, HINSTANCE hPrevInstance, int nCmdShow)
{
    HWND hwnd;
    WNDCLASS w;
    int x0, y0;
    int width = 1000, height = 700;
    const char * name="interpreter";
    x0 = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
    y0 = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
    memset(&w, 0, sizeof(WNDCLASS));
    w.style = CS_HREDRAW | CS_VREDRAW;
    w.lpfnWndProc = WndProc;
    w.hInstance = hInst;
    w.hCursor = LoadCursor(NULL, IDC_ARROW);
    w.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    w.lpszClassName = name;
    RegisterClass(&w);
    hwnd = CreateWindow(name, name, WS_OVERLAPPEDWINDOW, x0, y0, width, height, NULL, NULL, hInst, NULL);
    if (NULL == hwnd)
        return 0;
    hdc = GetDC(hwnd);
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    SetCursor(LoadCursor(hInst, IDC_ARROW));
    return 1;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
    if (registerWindow(hInstance, hPreInstance, nCmdShow) == 0)
    {
        showMessage(1, "window init error");
        return 1;
    }
    parser(filename);
    MSG Msg;
    while (GetMessage(&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

void showMessage(int flag, const char *msg1)
{
    const char *msg2 = "prompt";
    const char *msg3 = "error";
    if (flag == 0)
        MessageBox(NULL, msg1, msg2, MB_OK | MB_ICONINFORMATION);
    else
        MessageBox(NULL, msg1, msg3, MB_OK | MB_ICONERROR);
}

void drawPixel(unsigned long x, unsigned long y, unsigned int colorValue)
{
    COLORREF color = RGB(255, 0, 0);
    SetPixel(hdc, x, y, color);
    SetPixel(hdc, x+1, y, color);
    SetPixel(hdc, x, y+1, color);
    SetPixel(hdc, x+1, y+1, color);
}
#endif