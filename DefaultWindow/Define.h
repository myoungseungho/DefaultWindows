#pragma once

#define WINCX		800
#define WINCY		600

#define WINCX_SMALL		700
#define WINCY_SMALL		500

#define PURE		= 0


template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

typedef struct tagInfo
{
	float	fX;
	float	fY;
	float	fCX;
	float	fCY;

}INFO;



extern HWND g_hWnd;