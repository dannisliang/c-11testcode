/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: m18li
 *
 * Created on 2016年9月9日, 下午7:19
 */

#include <cstdlib>
#include <iostream>
#include "SyncQueue.hpp"
#include "ThreadPool.hpp"
using namespace std;

/*
 * 
 */
void testThread(ThreadPool *pool)
{
        for (int i = 0; i < 10; i++)
        {
                auto thdId = this_thread::get_id();
                pool->AddTask([thdId]{
                        cout << "sync thread 2 ID" << thdId << endl;
                });
                
        }
}

int main(int argc, char** argv) {
	cout << "Thread test started" << endl;
        ThreadPool pool;
        pool.Start(2);
        std::thread thd1 ([&pool]{
                for (int i = 0; i < 10; i++)
           {
                        auto thdId = this_thread::get_id();
                        pool.AddTask([thdId]{
                        cout << "sync thread 1 ID" << thdId << endl;
                });
           }
        });
        
       /*         std::thread thd2 ([&pool]{
                for (int i = 0; i < 10; i++)
           {
                        auto thdId = this_thread::get_id();
                        pool.AddTask([thdId]{
                        cout << "sync thread 2 ID" << thdId << endl;
                });
           }
        });*/
        std::thread thd2(testThread,&pool);
        
        this_thread::sleep_for(std::chrono::seconds(2));
        pool.Stop();
        thd1.join();
        thd2.join();
	return 0;
}

