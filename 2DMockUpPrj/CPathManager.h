#pragma once
class CPathManager
{
	SINGLETON(CPathManager);

private:
	WCHAR m_szContentPath[255];

public:
	void init();

};

