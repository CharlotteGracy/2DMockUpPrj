#include "framework.h"
#include "CPathManager.h"


CPathManager::CPathManager() {

	m_strContentPath[0] = {};
}
CPathManager::~CPathManager() {

}

void CPathManager::init() {
	GetCurrentDirectory(255, m_strContentPath);

	//���� ������
	int iLen = wcslen(m_strContentPath); //wchar_t ���ڿ� ���� Ȯ��

	for (int i = iLen - 1; i = 0; i--) {
		if ('\\' == m_strContentPath[i]) {
			m_strContentPath[i] = '\0';
			break;
		}
	}


	wcscat_s(m_strContentPath, 255, L"\\bin\\content\\"); //wchar ���ڿ� �ڿ� ���ڿ� ���̱�

	Logger::info(m_strContentPath);



}

const wchar_t* CPathManager::GetContentPath() {
	return m_strContentPath;
}

