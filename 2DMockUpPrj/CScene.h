#pragma once

// ���� ����: �ش� Ŭ������ ������ ������ ����� �� �ְ� ����.
// 1. ��������� ������ ȣ��Ǿ� #pragma�� ���� ����ΰ� Ȯ�� �Ұ��� ���� �ذ�
// 2. ������ �ӵ��� ����.

class CGameObject;



class CScene
{
private:
	vector<CGameObject*> m_arrObj[(int)GROUP_GAMEOBJ::SIZE];
	wstring m_strName;

public:
	CScene();
	virtual ~CScene();

	virtual void update();
	virtual void render(HDC hDC);
	virtual void finalupdate();
	virtual void Enter() = 0;
	virtual void Exit() = 0;




	void SetName(const wstring& strName);
	wstring GetName();

	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ type);




};

