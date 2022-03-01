#include "framework.h"
#include "Ccore.h"
#include "CGameObject.h"


CGameObject object;

CCore::CCore() {
	//���� ȭ���� �׸��� ���� DC �ڵ鰪 �ʱ�ȭ
	m_hDC = 0;
}

CCore::~CCore() {
	//���� �ھ� ���� ������ DC �ڵ鰪 �ݳ�
	ReleaseDC(hWnd, m_hDC);
}


void CCore::update() {
//���� ���� ���� ����

	CTimeManager::getInst()->update();
	//TODO: getInst ��� �������µ� ��ü ��� ���� �� �� ���� ����

	fPoint pos = object.GetPos();


	// GetAsuncKeyState: �޽��� ť�� Ű �Է��� �޴� ����� �ƴ� ���� ������ Ű �Է»��¸� Ȯ��

	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		pos.x -= 100 * CTimeManager::getInst()->GetDT();
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		pos.x += 100 * CTimeManager::getInst()->GetDT();
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		pos.y -= 100 * CTimeManager::getInst()->GetDT();
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		pos.y += 100 * CTimeManager::getInst()->GetDT();
	}

	object.SetPos(pos);
}

void CCore::render() {

	Rectangle(m_hDC,
		object.GetPos().x - object.GetScale().x / 2,
		object.GetPos().y - object.GetScale().y / 2,
		object.GetPos().x + object.GetScale().x / 2,
		object.GetPos().y + object.GetScale().y / 2
		);


	Rectangle(m_hDC,
		object.GetPos().x - object.GetScale().x / 2 +200,
		object.GetPos().y - object.GetScale().y / 2,
		object.GetPos().x + object.GetScale().x / 2+200,
		object.GetPos().y + object.GetScale().y / 2
	);

	Rectangle(m_hDC,
		object.GetPos().x - object.GetScale().x / 2,
		object.GetPos().y - object.GetScale().y / 2 +200,
		object.GetPos().x + object.GetScale().x / 2,
		object.GetPos().y + object.GetScale().y / 2 +200
	);
	Rectangle(m_hDC,
		object.GetPos().x - object.GetScale().x / 2+200,
		object.GetPos().y - object.GetScale().y / 2+200,
		object.GetPos().x + object.GetScale().x / 2+200,
		object.GetPos().y + object.GetScale().y / 2+200
	);

	//������ ��ܿ� FPS ǥ��
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager:getInst()->GetFPS());
	TextOutW(m_hDC, WINSIZEX - 50, 10, strFPS, 5);
}

void CCore::init() {
	CTimeManager::getInst()->init();
	m_hDC = GetDC(hWnd);
	object = CGameObject(fPoint{ 100,100 }, fPoint{ 100,100 });
}