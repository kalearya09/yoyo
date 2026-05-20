#include<iostream>
#include<thread>
#include<mutex>
#include<semaphore>
using namespace std;
const int N=5;
mutex forks[N];
binary_semaphore room(4);
void philosopher(int id){
 room.acquire();
 forks[id].lock();
 forks[(id+1)%N].lock();
 cout<<"Philosopher "<<id<<" is eating"<<endl;
 forks[id].unlock();
 forks[(id+1)%N].unlock();
 room.release();}
int main(){
 thread p[N];
 for(int i=0;i<N;i++)
 p[i]=thread(philosopher,i);
 for(int i=0;i<N;i++)
 p[i].join();
 return 0; }
