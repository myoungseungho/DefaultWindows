#pragma once

#define WINCX		800
#define WINCY		600

#define WINCX_SMALL		700
#define WINCY_SMALL		500

#define PURE		= 0

#define			OBJ_NOEVENT	 0
#define			OBJ_DEAD	 1

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


enum DIRECTION
{
	DIR_LEFT,
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LUP,
	DIR_RUP,
	DIR_LDOWN,
	DIR_RDOWN,
	DIR_END
};

extern HWND g_hWnd;

enum OBJID
{
	OBJ_PLAYER,
	OBJ_BULLET,
	OBJ_MONSTER,
	OBJ_MOUSE,
	OBJ_END
};
