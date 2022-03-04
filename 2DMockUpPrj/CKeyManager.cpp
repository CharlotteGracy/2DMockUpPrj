#include "framework.h"
#include "CKeyManager.h"

CKeyManager::CKeyManager() {

	//키 상태를 모두 눌리지 않은 상태로 초기화
	for (int key = 0; key < VKEY_SIZE; key++) {

	}
}

CKeyManager::~CKeyManager() {

}

void CKeyManager::update() {

}

void CKeyManager::init() {

}

bool CKeyManager::GetButtonUP(const int key) {
	return false;

}

bool CKeyManager::GetButtonDOWN(const int key) {
	return false;
}

