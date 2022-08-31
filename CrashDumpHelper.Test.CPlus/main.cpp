#include <windows.h>
#include <iostream>
#include "detours.h"
using namespace std;


auto strcmp_Real = strcmp;
int __cdecl strcmp_Stub(
	_In_z_ char const* _Str1,
	_In_z_ char const* _Str2
)
{
	return 0;
}


int main()
{
	// =============== These take effect only in Debug mode ========================
	// LONG bRet = DetourRestoreAfterWith();
	// cout << "DetourRestoreAfterWith: " << bRet << endl;
	// bRet = DetourTransactionBegin();
	// cout << "DetourTransactionBegin: " << bRet << endl;
	// bRet = DetourUpdateThread(GetCurrentThread());
	// cout << "DetourUpdateThread: " << bRet << endl;
	// bRet = DetourAttach(&(PVOID&)strcmp_Real, &strcmp_Stub);
	// cout << "DetourAttach: " << bRet << endl;
	// bRet = DetourTransactionCommit();
	// cout << "DetourTransactionCommit: " << bRet << endl;
	// =============== These take effect only in Debug mode ========================


	string str;
	while (true)
	{
		std::cin >> str;
		cout << strcmp(str.c_str(), "bbbbb") << endl;
	}
	
	return 0;
}
