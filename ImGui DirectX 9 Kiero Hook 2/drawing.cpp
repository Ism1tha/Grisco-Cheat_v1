#include "includes.h"

void DrawFontA(int X, int Y, D3DCOLOR Color, const char* text, ID3DXFont* pFont)
{
	RECT FontRect = { X, Y, X + 120, Y + 16 };
	pFont->DrawTextA(NULL, text, -1, &FontRect, DT_NOCLIP, Color);
}