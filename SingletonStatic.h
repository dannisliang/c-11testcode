/*
 * SingletonStatic.h
 *
 *  Created on: 2016Äê5ÔÂ29ÈÕ
 *      Author: Ãô
 */

#ifndef SINGLETONSTATIC_H_
#define SINGLETONSTATIC_H_
template<class T>
class SingletonStatic {
public:
	static T& Instance()
	{
		static T m_instance;
		return m_instance;
	}
	SingletonStatic(SingletonStatic const&)=delete;
	SingletonStatic& operator=(SingletonStatic const&)=delete;
protected:
	SingletonStatic();
	~SingletonStatic();

};

#endif /* SINGLETONSTATIC_H_ */
