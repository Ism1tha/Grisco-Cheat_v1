#include "includes.h"
#include "cgui.h"
#include "drawing.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

EndScene oEndScene = NULL;
WNDPROC oWndProc;
static HWND window = NULL;

HMODULE _hModule;

bool showMenu = false;
bool debugConsole = false;
bool bunnyHop = false;
bool espSnapLines = false;

ID3DXFont* pFont;

void InitImGui(LPDIRECT3DDEVICE9 pDevice)
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGuiStyle* style = &ImGui::GetStyle();
	CustomStyleImGui(style);
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX9_Init(pDevice);
}

bool initImGui = false;
bool initD3D9Drawing = false;
long __stdcall hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	if (!initImGui)
	{
		InitImGui(pDevice);
		initImGui = true;
	}

	if (!initD3D9Drawing) 
	{
		D3DXCreateFontA(pDevice, 14, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
			ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &pFont); //Doble puntero, lo pone en los parametros (ppFont)
		initD3D9Drawing = true;
	}

	if (showMenu) 
	{
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		ImGui::SetNextWindowSize(ImVec2(400, 200));
		ImGui::Begin("Grisco Cheat v1", &showMenu, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
		ImGui::Checkbox("Debug Console", &debugConsole);
		ImGui::Checkbox("Bunny Hop", &bunnyHop);
		ImGui::Checkbox("ESP Snap Lines", &espSnapLines);
		ImGui::End();
		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
	}
	DrawFontA(5, 5, D3DCOLOR_ARGB(255, 0, 255, 0), "Grisco Cheat v1 by Ism1tha", pFont); //Parámetro es 

	return oEndScene(pDevice);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (showMenu)
	{
		ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
		return true;
	}

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam)
{
	DWORD wndProcId;
	GetWindowThreadProcessId(handle, &wndProcId);

	if (GetCurrentProcessId() != wndProcId)
		return TRUE; // skip to next window

	window = handle;
	return FALSE; // window found abort search
}

HWND GetProcessWindow()
{
	window = NULL;
	EnumWindows(EnumWindowsCallback, NULL);
	return window;
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool attached = false;
	while (!attached)
	{
		if (kiero::init(kiero::RenderType::Auto) == kiero::Status::Success)
		{
			kiero::bind(42, (void**)&oEndScene, hkEndScene);
			do
			{
				window = GetProcessWindow();
			} while (window == NULL);
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWL_WNDPROC, (LONG_PTR)WndProc);
			attached = true;
		}
	}
	while (true)
	{
		// If INSERT key is pressed, toggle the menu
		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			showMenu = !showMenu;
		}
		// Else if END key is pressed, exit the cheat
		else if (GetAsyncKeyState(VK_END) & 1)
		{
			kiero::shutdown();
			FreeLibraryAndExitThread(_hModule, 0);
		}
		Sleep(30);
	}
	return 0;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		_hModule = hMod;
		DisableThreadLibraryCalls(_hModule);
		CreateThread(nullptr, 0, MainThread, _hModule, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
