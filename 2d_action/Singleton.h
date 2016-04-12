#pragma once
#include "stdafx.h"

template <class T>
class Singleton
{
public:
	static T* GetInstance()
	{
		if (m_instance == nullptr)
			m_instance = new T();
		return m_instance;
	}

	virtual void DestorySingleton()
	{
		delete this;
	}

protected:
	virtual ~Singleton()
	{
		delete m_instance;
		m_instance == nullptr;
	}

private:
	static T* m_instance;
};

template<class T> T* Singleton<T>::m_instance = nullptr;