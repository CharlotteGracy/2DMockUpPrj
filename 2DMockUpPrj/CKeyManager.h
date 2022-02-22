#pragma once
class CKeyManager
{
	SINGLETON(CKeyManager);

private:
	static const int VKEY_SIZE = 0xFF; 

	bool m_arrPrevKey[VKEY_SIZE];
	bool m_arrCurKey[VKEY_SIZE];

public:
	void update();
	void init();

	bool GetButton(const int key);
	bool GetButtonUP(const int key);
	bool GetButtonDOWN(const int key);

};