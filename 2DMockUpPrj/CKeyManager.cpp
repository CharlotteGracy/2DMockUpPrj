#include "framework.h"
#include "CKeyManager.h"

CKeyManager::CKeyManager() {

	//Ű ���¸� ��� ������ ���� ���·� �ʱ�ȭ
	for (int key = 0; key < VKEY_SIZE; key++) {

	}
}

CKeyManger::~CKeyManager() {

}

void CKeyManger::update() {

}

void CKeyManager::init() {

}

bool CKeyManager::GetButtonUP(const int key) {
	return false;

}

bool CKeyManager::GetButtonDOWN(const int key) {
	return false;
}
