#include "framework.h"
#include "CGameObject.h"


CGameObject::CGameObject() {
	
}

CGameObject::CGameObject(fPoint pos, fPoint scale) {
	m_fptPos = pos;
	m_fptScale = scale;
}

CGameObject::CGameObject() {

}

void CGameObject::SetPos(fPoint pos) {
	m_fptPos = pos;
}


void CGameObject::SetScale(fPoint scale) {
	m_fptScale = scale;
}

void CGameObject::GetPos() {
	return m_fptPos;
}

void CGameObject::GetScale() {
	return m_fptScale;
}



