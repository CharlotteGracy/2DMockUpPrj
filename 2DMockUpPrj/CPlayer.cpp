#include "framework.h"
#include "CPlayer.h"
#include "CTexture.h"


CPlayer::CPlayer() {

	m_pTex = new CTexture;

	wstring strFilepath = CPathManager::getInst()->GetContentPath();
	strFilepath += L"texture\\Player.bmp";
	m_pTex->Load(strFilepath);

}

CPlayer::~CPlayer() {

	if (nullptr != m_pTex) {
		delete m_pTex;
	}

}


void CPlayer::update() {
	fPoint pos = GetPos();

	if (Key(VK_LEFT)) {
		pos.x -= 100 * fDT;
	}
	if (Key(VK_RIGHT)) {
		pos.x += 100 * fDT;
	}
	if (Key(VK_UP)) {
		pos.y -= 100 * fDT;
	}
	if (Key(VK_DOWN)) {
		pos.y += 100 * fDT;
	}

	SetPos(pos);

	if (KeyDown(VK_SPACE)) {
		CreateMissile();
	}

}

void CPlayer::render(HDC hDC) {
	int iWidth = (int)(m_pTex->GetBmpWidth());
	int iHeight = (int)(m_pTex->GetBmpHeight());

	fPoint pos = GetPos();

	BitBlt(hDC,
		(int)(pos.x - (float)(iWidth / 2)),
		(int)(pos.y - (float)(iHeight / 2),
			iWidth, iHeight,
			m_pTex->GetDC(),
			0, 0, SRCCOPY);
}



void CPlayer::CreateMissile() {
/*	fPoint fpMissilePos = GetPos();
	fpMissilePos.x += GetScale().x/2.f

	*/
}
