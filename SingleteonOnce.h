/*
 * SingleteonOnce.h
 *
 *  Created on: 2016Äê5ÔÂ29ÈÕ
 *      Author: Ãô
 */

#ifndef SINGLETEONONCE_H_
#define SINGLETEONONCE_H_
#include <mutex>
#include <memory>
#include <thread>
template <class T>
class SingleteonOnce {
public:

	static T& Instance() {
		std::call_once(instanceFlag,[](){
			m_pInstance.reset(new T);
		});
		return *m_pInstance;
	}

	SingleteonOnce(SingleteonOnce const&)=delete;
    SingleteonOnce& operator=(SingleteonOnce const&)=delete;
protected:
    SingleteonOnce(){};
    ~SingleteonOnce(){};
private:
	static std::once_flag instanceFlag;
	static std::unique_ptr<T> m_pInstance;
};
template <class T>
std::once_flag SingleteonOnce<T>::instanceFlag;
template <class T>
std::unique_ptr<T> SingleteonOnce<T>::m_pInstance;

#endif /* SINGLETEONONCE_H_ */
