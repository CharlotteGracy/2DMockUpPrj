#pragma once
class CGameObject
{

private:
	fPoint m_fptPos;
	fPoint m_fptScale;

public:
	CGameObject();
	CGameObject(fPoint pos, fPoint scale);
	virtual ~CGameObject();

	void SetPos(fPoint pos);
	void SetScale(fPoint scale);

	fPoint GetPos();
	fPoint GetScale();

	void update();
	void render(HDC hDC);
};


