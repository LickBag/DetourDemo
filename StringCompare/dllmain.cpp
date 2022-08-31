// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "StringCompare.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    DWORD threadID = 0;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        StringCompare(nullptr);
        break;
    case DLL_THREAD_ATTACH:
        
        break;
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

