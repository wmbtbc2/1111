#include <Windows.h>
#include <stdio.h>

typedef LRESULT(WINAPI * MyProc)(int code, WPARAM wp, LPARAM lp); // export from calc_dll.dll

int main()
{
	auto pStartupInfo = new STARTUPINFO();
	auto pProcessInfo = new PROCESS_INFORMATION();

	CreateProcess(L"C:/Program Files (x86)/Steam/steamapps/common/Counter-Strike Global Offensive/csgo.exe", L" -secure -safe -steam -novid -tickrate 128", nullptr, nullptr, FALSE, NORMAL_PRIORITY_CLASS, nullptr, nullptr, pStartupInfo, pProcessInfo);
	Sleep(15000);

	HMODULE dll = LoadLibrary(L"module.dll");
	HOOKPROC addr = (HOOKPROC)GetProcAddress(dll, "Test");
	HHOOK ass = SetWindowsHookEx(WH_KEYBOARD, addr, dll, pProcessInfo->dwThreadId);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{

	}
	UnhookWindowsHookEx(ass);
	FreeConsole();
	exit(0);
}

