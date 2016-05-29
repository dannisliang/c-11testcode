/*
 * singleton.h
 *
 *  Created on: 2016Äê5ÔÂ28ÈÕ
 *      Author: Ãô
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <stddef.h>  // defines NULL
#include <mutex>
#include <iostream>

template <class T>
class Singleton
{
public:

  static T* Instance() {
	  std::mutex m;
      if(!m_pInstance)
      {
    	  m.lock();
    	  if(!m_pInstance)
    	  {
    	   	  m_pInstance = new T;
    	  }
    	  m.unlock();
      }
      return m_pInstance;
  }
  void TestOut();

protected:
  Singleton();
  ~Singleton();
private:
  Singleton(Singleton const&);
  Singleton& operator=(Singleton const&);
  static T* m_pInstance;
};

template <class T> T* Singleton<T>::m_pInstance=NULL;
#endif /* SINGLETON_H_ */
