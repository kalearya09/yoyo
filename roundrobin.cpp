#include<iostream>
using namespace std;
int main(){
 int n,tq;
 cin>>n;
 int at[20],bt[20],rt[20],ct[20],
wt[20],tat[20];
 for(int i=0;i<n;i++){
 cin>>at[i]>>bt[i];
 rt[i]=bt[i]; }
 cin>>tq;
 int time=0,done=0;
 float awt=0,atat=0;
 while(done<n){
 bool f=false;
 for(int i=0;i<n;i++){
 if(at[i]<=time && rt[i]>0){
 f=true;
 if(rt[i]>tq){
 time+=tq;
 rt[i]-=tq; }
 else{
 time+=rt[i];
 rt[i]=0;
 ct[i]=time;
 tat[i]=ct[i]-at[i];
 wt[i]=tat[i]-bt[i];
 awt+=wt[i];
 atat+=tat[i];
 done++; } } }
 if(!f) time++; }
 cout<<"PID AT BT CT TAT WT\n";
 for(int i=0;i<n;i++)
 cout<<i+1<<" "<<at[i]<<" "<<bt[i]<<" "
 <<ct[i]<<" "<<tat[i]<<" "<<wt[i]<<"\n";
 cout<<"\nAvg WT="<<awt/n;
 cout<<"\n
