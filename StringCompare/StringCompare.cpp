#include "pch.h"
#include "framework.h"
#include "StringCompare.h"
#include "detours.h"
#include <iostream>
using namespace std;

bool g_bHooked = false;

auto strcmp_Real = strcmp;
int __cdecl strcmp_Stub(
    _In_z_ char const* _Str1,
    _In_z_ char const* _Str2
)
{
    cout << _Str1 << endl;
    cout << _Str2 << endl;

    return strcmp_Real(_Str1, _Str2);
}

auto wcscmp_Real = wcscmp;
int __cdecl wcscmp_Stub(
    _In_z_ wchar_t const* _String1,
    _In_z_ wchar_t const* _String2
)
{
    cout << _String1 << endl;
    cout << _String2 << endl;

    return wcscmp_Real(_String1, _String2);
}

// =========== This function is called by DllMain ===========
// =========== This dll is inject by Xenos.exe ===========
// =========== direct call this export function also take no effect ===========
void __stdcall StringCompare(wchar_t*)
{
    if (!g_bHooked)
    {
        // !!!!!!!!!!! ===========  These return 0, but take no effect ================= !!!!!!!!!!!
        LONG bRet = DetourRestoreAfterWith();
        cout << "DetourRestoreAfterWith: " << bRet << endl;
        bRet = DetourTransactionBegin();
        cout << "DetourTransactionBegin: " << bRet << endl;
        bRet = DetourUpdateThread(GetCurrentThread());
        cout << "DetourUpdateThread: " << bRet << endl;
        bRet = DetourAttach(&(PVOID&)strcmp_Real, &strcmp_Stub);
        cout << "DetourAttach: " << bRet << endl;
        bRet = DetourAttach(&(PVOID&)wcscmp_Real, &wcscmp_Stub);
        cout << "DetourAttach: " << bRet << endl;
        bRet = DetourTransactionCommit();
        cout << "DetourTransactionCommit: " << bRet << endl;
        // !!!!!!!!!!! ===========  These return 0, but take no effect ================= !!!!!!!!!!!


        g_bHooked = true;
    }
    
    return;
}