#pragma once

class CGameObject;

class CCollider
{
	friend Class CGameObject;

private:
	CGameObject* m_pOwner;
	fPoint m_fptOffsetPos;
	fPoint m_fptFinalPos;


public:
	CCollider();
	~CCollider();

	void finalupdate();
};

