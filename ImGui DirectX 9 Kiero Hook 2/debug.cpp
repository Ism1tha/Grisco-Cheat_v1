#include "includes.h";
#include <cstdio>

FILE* f;
bool consoleInitialized = false;

void EnableDebugConsole()
{
	if (consoleInitialized)
		return;

	FILE* f;
	AllocConsole();
	freopen_s(&f, "CONOUT$", "w", stdout);
	printf("Grisco Cheat v1 Debug Console:\n");
	consoleInitialized = true;
	SetConsoleTitleA("Grisco Cheat v1 Debug Console");
}

void DisableDebugConsole()
{
	if (!consoleInitialized)
		return;

	FreeConsole();

	HWND hWND = FindWindowA(NULL, "Grisco Cheat v1 Debug Console");
	if (hWND != NULL)
	{
		SendMessage(hWND, WM_CLOSE, 0, 0);
	}

	consoleInitialized = false;
}