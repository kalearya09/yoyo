//sjf preemptive
#include<iostream>
using namespace std;
int main(){
 int n;
 cin>>n;
 int at[20],bt[20],rt[20],ct[20],wt[20],tat[20];
 for(int i=0;i<n;i++){
 cin>>at[i]>>bt[i];
 rt[i]=bt[i]; }
 int time=0,completed=0;
 float awt=0,atat=0;
 while(completed<n){
 int idx=-1,minbt=9999;
 for(int i=0;i<n;i++){
 if(at[i]<=time && rt[i]>0 && rt[i]<minbt){
 minbt=rt[i];
 idx=i; } }
 if(idx!=-1){
 rt[idx]--;
 time++;
 if(rt[idx]==0){
 ct[idx]=time;
 tat[idx]=ct[idx]-at[idx];
 wt[idx]=tat[idx]-bt[idx];
 awt+=wt[idx];
 atat+=tat[idx];
 completed++; }}
 else time++; }
 cout<<"PID AT BT CT TAT WT\n";
 for(int i=0;i<n;i++)
 cout<<i+1<<" "<<at[i]<<" "<<bt[i]<<" "
 <<ct[i]<<" "<<tat[i]<<" "<<wt[i]<<"\n";
 cout<<"\nAvg WT="<<awt/n;
 cout<<"\nAvg TAT="<<atat/n; return 0; }





 //non premptive
#include<iostream>
using namespace std;
int main(){
 int n; cin>>n;
 int at[20],bt[20],pr[20],ct[20],
 wt[20],tat[20],done[20]={0};
 for(int i=0;i<n;i++)
 cin>>at[i]>>bt[i]>>pr[i];
 int time=0,completed=0;
 float awt=0,atat=0;
 while(completed<n){ int idx=-1,minp=9999;
 for(int i=0;i<n;i++){
 if(at[i]<=time && !done[i] && pr[i]<minp){
 minp=pr[i]; idx=i; }}
 if(idx!=-1){
 time+=bt[idx]; ct[idx]=time;
 tat[idx]=ct[idx]-at[idx];
 wt[idx]=tat[idx]-bt[idx];
 awt+=wt[idx]; atat+=tat[idx];
 done[idx]=1; completed++; }
 else time++; }
 cout<<"PID AT BT PR CT TAT WT\n";
 for(int i=0;i<n;i++)
 cout<<i+1<<" "<<at[i]<<" "<<bt[i]<<" "<<pr[i]<<" "
 <<ct[i]<<" "<<tat[i]<<" "<<wt[i]<<"\n";
 cout<<"\nAvg WT="<<awt/n; cout<<"\nAvg TAT="<<atat/n; return 0; }
