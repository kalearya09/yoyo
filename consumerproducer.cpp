#include<iostream>
#include<thread>
#include<mutex>
#include<semaphore>
using namespace std;
int buffer[5], in=0, out=0;
counting_semaphore<5> empty(5);
counting_semaphore<5> full(0);
mutex mtx;
void producer(int id){
 for(int i=1;i<=5;i++){
 empty.acquire();
 mtx.lock();
 buffer[in]=i;
 cout<<"Producer "<<id<<" produced "<<i<<endl;
 in=(in+1)%5;
 mtx.unlock();
 full.release(); }}
void consumer(int id){
 for(int i=1;i<=5;i++){
 full.acquire();
 mtx.lock();
 cout<<"Consumer "<<id<<" consumed "<<buffer[out]<<endl;
 out=(out+1)%5;
 mtx.unlock();
 empty.release(); }}
int main(){
 thread p1(producer,1), c1(consumer,1);
 p1.join();
 c1.join();
 return 0; }
