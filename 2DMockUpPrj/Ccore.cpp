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

	fPoint pos = object.GetPos();


	// GetAsuncKeyState: �޽��� ť�� Ű �Է��� �޴� ����� �ƴ� ���� ������ Ű �Է»��¸� Ȯ��

	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		pos.x -= 0.01;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		pos.x += 0.01;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		pos.y -= 0.01;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		pos.y += 0.01;
	}

	object.SetPos(pos);
}

void CCore::render() {

	Rectangle(m_hDC,
		object.GetPos().x - object.GetScale().x / 2,
		object.GetPos().y - object.GetScale.y / 2,
		object.GetPos().x + object.GetScale.x / 2,
		object.GetPos().y + object.GetScale.y / 2,
		);


}

void CCore::init() {
	m_hDC = GetDC(hWnd);
	object = CGameObject(fPoint{ 100,100 }, fpoint{ 100,100 });
}