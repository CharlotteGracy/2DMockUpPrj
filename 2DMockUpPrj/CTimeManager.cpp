#include "framework.h"
#include "CTimeManager.h"


CTimeManager::CTimeManager(){
}

CTimeManager::~CTimeManager() {

}

void CTimeManager::update() {
	static unsigned int updateCount = 0;
	static double updateOneSecond = 0;


	QueryPerformanceCounter(&m_llCurCount);
	//���� �������� ī���ð�, ���� ������ ī���� ���� ���̸� ����.
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / m_llFrequency.QuadPart;
	//���� �������� ���� ������ ī���� ������ �ִ´�
	m_llPrevCount = m_llCurCount;

	++updateCount;
	updateOneSecond += m_dDT;
	if (updateOneSecond >= 1.0) {
		m_uiFPS = updateCount;

		updateOneSecond = 0;
		updateCount = 0;
	}
}

void CTimeManager::init() {
	QueryPerformanceCounter(&m_llCurCount);
	QueryPerformanceFrequency(&m_llFrequency);
}

unsigned int CTimeManager::GetFPS() {
	return m_uiFPS;
}

double CTimeManager::GetDT() {
	return m_dDT;
}