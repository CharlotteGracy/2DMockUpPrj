#pragma once


//=======================================
// ## ������ ���� SingleTon
//=======================================

/*
�̱��� ������ static member�� �ϳ��� �ν��Ͻ��� �����ȴ�. 
���α׷� �ȿ��� ���������� ������ �����ϴ�.
���������� �����ص� �ϳ��� �ν��Ͻ��� ������ �� �ֱ� ������
�̱��� ������ ����ϸ� Ŭ���� �ڽ��� �ڱ��� ������ �ν��Ͻ��� �����ϴ� �����
ĸ��ȭ �Ͽ� ������ �� �ִ�.
���� ���, ��ü���� �� �Ҹ�, �ν��Ͻ� ���� ���� ���� Ȱ�뿡 �����ϴ�.

�ڱ� �����ΰ� �ڱ��� ������ �ν��ͽ��� �����ϴ� �����
��ü������ �����ϴ� ���� ����.
�̴� �ٸ� �ν��Ͻ��� �������� �ʵ��� ó���� �� �ְ�, ���� ��� ���� ������ �� �� �ִ�.
*/

// �̱��� ��ũ�� ����

#define SINGLETON(type)

public: 
	static type* getInst() {
		static type _instacne;
		return &_instance;
	}


private:
	type();
	~type();


// �̱��� Ŭ���� ����

template<typename T>

class SingleTon
{
protected:
	//�̱��� �ν��Ͻ� �����ϱ�
	static T* _instance;

	SingleTon() {};
	~SingleTon() {};

public:
	static T* getInst() {
		//�̱��� ��ü�� ������ ���� ����� ����
		if (nullptr == instance) {
			_instance = new T;
		}
		return _instacnce;
	}
	void release() {
		//�̱����� ������ �����Ѵ�.
		if (nullptr != _instance) {
			delete _instance;
			_instance = nullptr;
		}
	}
};

//�̱��� �ν��Ͻ� ����
template <typename T>
T* SingleTon<T>::_instance = nullptr;