#include "stdafx.h"
#include "CollisionMgr.h"

CCollisionMgr::CCollisionMgr()
{
}

CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src)
{
	for (auto Dst_iter : _Dst)
	{
		RECT Dst_Rect = Dst_iter->Get_RECT();

		for (auto Src_iter : _Src)
		{
			RECT Src_Rect = Src_iter->Get_RECT();
			RECT testRC{};

			if (IntersectRect(&testRC, &Dst_Rect, &Src_Rect))
			{
				Dst_iter->Update_Die();
				Src_iter->Update_Die();
			}
		}
	}
}

void CCollisionMgr::Collision_Sphere(list<CObj*> pDst, list<CObj*> pSrc)
{
	for (auto Dst_iter : pDst)
	{
		for (auto Src_iter : pSrc)
		{
			if (Check_Sphere(Dst_iter, Src_iter))
			{
				Dst_iter->Update_Die();
				Src_iter->Update_Die();
			}
		}
	}
}

bool CCollisionMgr::Check_Sphere(CObj* pDst, CObj* pSrc)
{
	float	fWidth = abs(pDst->Get_Info().fX - pSrc->Get_Info().fX);
	float	fHeight = abs(pDst->Get_Info().fY - pSrc->Get_Info().fY);

	float	fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

	float	fRadius = (pDst->Get_Info().fCX + pSrc->Get_Info().fCX) * 0.5f;

	return fRadius >= fDiagonal;
}
