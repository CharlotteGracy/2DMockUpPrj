#include "framework.h"
#include "CKeyManager.h"

CKeyManager::CKeyManager() {

	//Ű ���¸� ��� ������ ���� ���·� �ʱ�ȭ
	for (int key = 0; key < VKEY_SIZE; key++) {

	}
}

CKeyManager::~CKeyManager() {

}

void CKeyManager::update() {
	//���� ����(Focus)�� �����찡 ���� �������ΰ��� Ȯ�� 
	HWND curWnd = GetFocus();
	if (hWnd != curWnd) {
		//�����찡 ����(Focus)�� ���°� �ƴ� ��� Ű�Է��� ������Ŵ
		for (int key = 0; key < VKEY_SIZE; key++) {
			m_arrPrevKey[key] = m_arrCurKey[key];
			m_arrCurKey[key] = false;
		}
		return;
	}
	// ��� Ű �����ŭ �ݺ��ϸ� �Է»��� Ȯ��
	for (int key = 0; key < VKEY_SIZE; key++) {
		m_arrPrevKey[key] = m_arrCurKey[key];
		m_arrCurKey[key] = false;
	}

}

void CKeyManager::init() {

}

bool CKeyManager::GetButtonUP(const int key) {
	return false;

}

bool CKeyManager::GetButtonDOWN(const int key) {
	return false;
}

