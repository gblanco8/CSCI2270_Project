////////////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <iostream>

#include "Project.hpp"
#include "Project.cpp"

#define FILE_MENU_HELLO 1
#define HELP_MENU_CONTACT 2
#define FILE_MENU_EXIT 3
#define ADD_PROFILE 4
#define ADD_TASK 5
#define DISPLAY_TASKS 6
#define COMPLETE_TASK 7
#define DISPLAY_PROFILES 8


const char g_szClassName[] = "myWindowClass";

HWND hName, hLength, hTime, hCat, hProfile, hTask, hCatWeight;
HMENU hMenu;
// HMENU hEdit;
////////////////////////////////////////////////////////////////////////////////
void AddMenus(HWND hWnd){
  hMenu = CreateMenu();
  HMENU hFileMenu = CreateMenu();
  HMENU hSubMenu = CreateMenu();
  HMENU hHelpMenu = CreateMenu();

  AppendMenu(hHelpMenu, MF_STRING, HELP_MENU_CONTACT, "Contact");

  AppendMenu(hFileMenu, MF_POPUP, FILE_MENU_HELLO, "Hello");
  AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL);
  AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, "Exit");

  AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
  AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hHelpMenu, "Help");

  SetMenu(hWnd, hMenu);
}
////////////////////////////////////////////////////////////////////////////////
void AddControls(HWND hWnd){

  CreateWindowW(L"Static", L"WELCOME!", WS_VISIBLE | WS_CHILD | SS_CENTER, 425, 25, 75, 15, hWnd, NULL, NULL, NULL);


  CreateWindowW(L"Button", L"Add Profile", WS_VISIBLE | WS_CHILD | WS_BORDER, 25, 65, 150, 50, hWnd, (HMENU)ADD_PROFILE, NULL, NULL);
  hProfile = CreateWindowW(L"EDIT", L"'ENTER PROFILE NAME'", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 190, 65, 150, 50, hWnd, NULL, NULL, NULL);


  CreateWindowW(L"Button", L"Add Task", WS_VISIBLE | WS_CHILD | WS_BORDER, 25, 130, 150, 50, hWnd, (HMENU)ADD_TASK, NULL, NULL);
  hName = CreateWindowW(L"EDIT", L"'ENTER TASK NAME'", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 190, 130, 150, 50, hWnd, NULL, NULL, NULL);
  hLength = CreateWindowW(L"EDIT", L"'ENTER TASK LENGTH'", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 355, 130, 150, 50, hWnd, NULL, NULL, NULL);
  hTime = CreateWindowW(L"EDIT", L"'ENTER TASK TIME'", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 520, 130, 150, 50, hWnd, NULL, NULL, NULL);
  hCat = CreateWindowW(L"EDIT", L"'ENTER TASK CATEGORY NAME'", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 685, 130, 150, 50, hWnd, NULL, NULL, NULL);
  hCatWeight = CreateWindowW(L"EDIT", L"'ENTER CATEGORY WEIGHT'", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 850, 130, 150, 50, hWnd, NULL, NULL, NULL);


  CreateWindowW(L"Button", L"Display Current Tasks", WS_VISIBLE | WS_CHILD | WS_BORDER, 25, 195, 150, 50, hWnd, (HMENU)DISPLAY_TASKS, NULL, NULL);


  CreateWindowW(L"Button", L"Complete Task", WS_VISIBLE | WS_CHILD | WS_BORDER, 25, 260, 150, 50, hWnd, (HMENU)COMPLETE_TASK, NULL, NULL);
  hTask = CreateWindowW(L"EDIT", L"'ENTER TASK NAME'", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 190, 260, 150, 50, hWnd, NULL, NULL, NULL);


  CreateWindowW(L"Button", L"Display Profiles", WS_VISIBLE | WS_CHILD | WS_BORDER, 25, 325, 150, 50, hWnd,  (HMENU)DISPLAY_PROFILES, NULL, NULL);
}

////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_COMMAND:

            switch(wParam){
              case FILE_MENU_EXIT:
                DestroyWindow(hWnd);
                break;
              case FILE_MENU_HELLO:
                MessageBeep(MB_ICONEXCLAMATION);
                break;
              case HELP_MENU_CONTACT:
                MessageBeep(MB_ICONEXCLAMATION);
                break;
              case ADD_PROFILE:
                char profile[30];
                GetWindowText(hProfile, profile, 30);
                addProfile(profile);
                break;
              case ADD_TASK:
                char name[30], length[10], time[10], weight[10], category[50];
                GetWindowText(hName, name, 30);
                GetWindowText(hLength, length, 10);
                GetWindowText(hTime, time, 10);
                GetWindowText(hCat, category, 50);
                GetWindowText(hCatWeight, weight, 10);
                addTask(name, length, (int)time, category, weight);
                break;
              case DISPLAY_TASKS:
                printList();
                break;
              case COMPLETE_TASK:
                char task[50];
                GetWindowText(hTask, task, 50);
                completeAnyTask(task);
                break;
              case DISPLAY_PROFILES:
                printProfiles();
                break;
            }

        break;
        case WM_CREATE:
            AddMenus(hWnd);
            AddControls(hWnd);
        break;
        case WM_CLOSE:
            DestroyWindow(hWnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow){
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    //Creates the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "It's Your To Do List, Bro",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 1000, 500,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    //The Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}
