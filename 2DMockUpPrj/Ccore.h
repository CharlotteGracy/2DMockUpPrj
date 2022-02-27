#pragma once
class CCore: public SingleTon<CCore>
{
//	SINGLETON(CCore);



public:
	void update();
	void render();

};