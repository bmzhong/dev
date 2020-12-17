#ifndef _THIS_IS_INTERPRETER_CPP
#define _THIS_IS_INTERPRETER_CPP

#define _SEMANTICS_

#include <cstdio>
#include <windows.h>
#include <wingdi.h>
#include <string>
#include "drawDot.hpp"
#include "../parser/parser.cpp"

using namespace std;
HDC hdc; // hdc是设备场景句柄,与绘图API（GDI函数）有关
string filename = "../testFile/draw4.txt";

// LRESULT: long
// wndProc 消息处理函数(接收处理windows消息)
// UINT : 32位无符号整型
// WPARAM wParam: 32位消息的特定附加信息,具体表示什么处决于message
// LPARAM lParam: 32位消息的特定附加信息,具体表示什么处决于message
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch (Message)
    {
        case WM_DESTROY: //关闭程序
            ReleaseDC(hwnd, hdc); //释放由调用GetDC或GetWindowDC函数获取的指定设备场景
            PostQuitMessage(0); //向线程投递一个退出消息。
            return 0;
        case WM_PAINT: //通过响应这个消息来完成窗口的绘制。
        {
            PAINTSTRUCT paint;  //绘图信息结构
            BeginPaint(hwnd, &paint); //此函数准备指定的绘画窗口，并使用有关绘画的信息填充PAINTSTRUCT结构。
//            parser(filename);
            EndPaint(hwnd, &paint); //EndPaint函数标记指定窗口的绘画过程结束；
        }
        default:
            return DefWindowProc(hwnd, Message, wParam, lParam); //调用缺省的窗口过程来为应用程序没有处理的任何窗口消息提供缺省的处理
    }
}
//注册窗口
//HINSTANCE hInstance,		当前应用程序实例的句柄
//HINSTANCE hPrevInstance,	系统中前一个应用程序实例的句柄，很少用到
//int nCmdShow				决定应用程序窗口显示方式的标志
int registerWindow(HINSTANCE hInst, HINSTANCE hPrevInstance, int nCmdShow)
{
    HWND hwnd; //指向窗口的句柄。
    WNDCLASS w; //窗口类结构体
    int x0, y0; //原点坐标
    int width = 1000, height = 700; //宽和高
    const char * name="interpreter"; //名字
    x0 = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
    y0 = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
    memset(&w, 0, sizeof(WNDCLASS));
    w.style = CS_HREDRAW | CS_VREDRAW;
    w.lpfnWndProc = WndProc; //设置窗体接收windws消息函数
    w.hInstance = hInst;
    w.hCursor = LoadCursor(NULL, IDC_ARROW);
    w.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    w.lpszClassName = name;
    RegisterClass(&w);
    hwnd = CreateWindow(name, name, WS_OVERLAPPEDWINDOW, x0, y0, width, height, NULL, NULL, hInst, NULL);
    if (NULL == hwnd)
        return 0;
    hdc = GetDC(hwnd); //用于获得hWnd参数所指定窗口的客户区域的一个设备环境。
    ShowWindow(hwnd, nCmdShow); //设置指定窗口的显示状态。
    UpdateWindow(hwnd); //UpdateWindow 绘制客户区，它实际上就是向窗口发送了一条 WM_PAINT 消息
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
    MSG Msg; //消息结构体
    while (GetMessage(&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg); //TranslateMessage 是用来把虚拟键消息转换为字符消息
        DispatchMessage(&Msg); //调度一个消息给窗口程序
    }
    return Msg.wParam;
}

void showMessage(int flag, const char *msg1)
{
    const char *msg2 = "prompt";
    const char *msg3 = "error";
    if (flag == 0)
        MessageBox(NULL, msg1, msg2, MB_OK | MB_ICONINFORMATION); //在屏幕上显示一个窗体
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