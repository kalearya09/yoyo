#include<iostream>
#include<thread>
#include<mutex>
#include<semaphore>
using namespace std;
int readcount=0;
mutex mtx;
binary_semaphore wrt(1);
void reader(int id){
 mtx.lock();
 readcount++;
 if(readcount==1)
 wrt.acquire();
 mtx.unlock();
 cout<<"Reader "<<id<<" is reading"<<endl;
 mtx.lock();
 readcount--;
 if(readcount==0)
 wrt.release();
 mtx.unlock();}
void writer(int id){
 wrt.acquire();
 cout<<"Writer "<<id<<" is writing"<<endl;
 wrt.release();}
int main(){
 thread r1(reader,1), r2(reader,2), w1(writer,1);
 r1.join();
 r2.join();
 w1.join();
 return 0; }
