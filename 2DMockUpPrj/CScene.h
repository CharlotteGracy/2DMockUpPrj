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
	~CScene();


	void SetName(const wstring& strName);
	wstring GetName();

	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ type);




};

