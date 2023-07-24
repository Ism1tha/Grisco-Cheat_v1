#include "includes.h"	
#include <cstdio>

DWORD dwGameBase = (DWORD)GetModuleHandleA("client.dll");
DWORD dwEngineBase = (DWORD)GetModuleHandleA("engine.dll");
DWORD dwClientState = (DWORD) nullptr;

void CheckCheats()
{
	if (consoleInitialized)
	{
	}
	if (bhopEnabled) CheckBHOP();
}

void CheckBHOP()
{
	DWORD dwClientState = *(DWORD*)(dwEngineBase + hazedumper::signatures::dwClientState);
	if (consoleInitialized && dwClientState) printf("dwClientState: %X\n", dwClientState);
	int localPlayer = *(int*)(dwClientState + hazedumper::signatures::dwClientState_GetLocalPlayer);
	DWORD entityList = *(DWORD*)(dwGameBase + hazedumper::signatures::dwEntityList);
	if (!entityList) return;
	DWORD localPlayerEntity = *(DWORD*)(dwGameBase + hazedumper::signatures::dwEntityList + localPlayer * 0x10); //IMPORTANT: NOT ENTITYLIST AND LATER LOCALPLAYER, ALL IN ONE!
	if (consoleInitialized && localPlayerEntity) printf("localPlayerEntity: %X\n", localPlayerEntity);
	//Get the flags of the local player
	int flags = *(int*)(localPlayerEntity + hazedumper::netvars::m_fFlags);
	if (consoleInitialized && flags) printf("flags: %d\n", flags);
	//Check if the local player is on the ground
	if (flags & (1 << 0) && GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		*(int*)(dwGameBase + hazedumper::signatures::dwForceJump) = 6;
	}
	}