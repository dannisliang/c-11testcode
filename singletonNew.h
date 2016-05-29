/*
 * singletonNew.h
 *
 *  Created on: 2016Äê5ÔÂ28ÈÕ
 *      Author: Ãô
 */

#ifndef SINGLETONNEW_H_
#define SINGLETONNEW_H_
#include <atomic>
#include <mutex>
#include <iostream>
class LogTesterNew
{
public:
	LogTesterNew();
	void LogStart()
	{
		std::cout << "Log Start" << std::endl;
	}
	~LogTesterNew()
	{

	}

};
template <class T>
class SingletonNew
{
public:

  static T* Instance() {
	  std::mutex m;
	  T* tmp = m_pInstance.load(std::memory_order_relaxed);
	  std::atomic_thread_fence(std::memory_order_acquire);
	  if(tmp == nullptr)
	  {
		  std::lock_guard<std::mutex> lock(m);
		  tmp = m_pInstance.load(std::memory_order_relaxed);
		  if(tmp == nullptr)
		  {
			  tmp = new T;
			  std::atomic_thread_fence(std::memory_order_release);
			  m_pInstance.store(tmp,std::memory_order_relaxed);
		  }
	  }

      return tmp;
  }
  void TestOut();

  SingletonNew(SingletonNew const&)=delete;
  SingletonNew& operator=(SingletonNew const&)=delete;
private:
  static std::atomic<T*> m_pInstance;
};

template <class T>
std::atomic<T*> SingletonNew<T>::m_pInstance;

#endif /* SINGLETONNEW_H_ */
