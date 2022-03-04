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
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);
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


	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	Rectangle(m_hMemDC,
		object.GetPos().x - object.GetScale().x / 2,
		object.GetPos().y - object.GetScale().y / 2,
		object.GetPos().x + object.GetScale().x / 2,
		object.GetPos().y + object.GetScale().y / 2
		);


	Rectangle(m_hMemDC,
		object.GetPos().x - object.GetScale().x / 2 +200,
		object.GetPos().y - object.GetScale().y / 2,
		object.GetPos().x + object.GetScale().x / 2+200,
		object.GetPos().y + object.GetScale().y / 2
	);

	Rectangle(m_hMemDC,
		object.GetPos().x - object.GetScale().x / 2,
		object.GetPos().y - object.GetScale().y / 2 +200,
		object.GetPos().x + object.GetScale().x / 2,
		object.GetPos().y + object.GetScale().y / 2 +200
	);
	Rectangle(m_hMemDC,
		object.GetPos().x - object.GetScale().x / 2+200,
		object.GetPos().y - object.GetScale().y / 2+200,
		object.GetPos().x + object.GetScale().x / 2+200,
		object.GetPos().y + object.GetScale().y / 2+200
	);

	//������ ��ܿ� FPS ǥ��
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCORY);
}

void CCore::init() {
	CTimeManager::getInst()->init();
	m_hDC = GetDC(hWnd);

	//���� ���۸��� �޸� DC�� ��Ʈ�� ����
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	object = CGameObject(fPoint(100, 100), fPoint{ 100,100 });



	object = CGameObject(fPoint{ 100,100 }, fPoint{ 100,100 });
}