#include<iostream>
using namespace std;
int main()
{ int block[50],process[50],allocation[50],b,p;
 cout<<"Enter number of blocks: "; cin>>b;
 cout<<"Enter size of blocks: "<<endl;
 for(int i=0;i<b;i++) cin>>block[i];
 cout<<"Enter number of processes: "; cin>>p;
 cout<<"Enter size of processes: "<<endl;
 for(int i=0;i<p;i++) cin>>process[i];
 // FIRST FIT
 cout<<"\nFirst Fit Allocation\n";
 int tempBlock1[50];
 for(int i=0;i<b;i++) tempBlock1[i]=block[i];
 for(int i=0;i<p;i++)
 { allocation[i]=-1;
 for(int j=0;j<b;j++)
 { if(tempBlock1[j]>=process[i])
 { allocation[i]=j;
 tempBlock1[j]-=process[i];
 break;} }
 if(allocation[i]!=-1) cout<<"Process "<<i+1<<" -> Block "<<allocation[i]+1<<endl;
 else cout<<"Process "<<i+1<<" -> Not Allocated"<<endl; }
 // BEST FIT
 cout<<"\nBest Fit Allocation\n";
 int tempBlock2[50];
 for(int i=0;i<b;i++) tempBlock2[i]=block[i];
 for(int i=0;i<p;i++)
 { allocation[i]=-1;
 int bestIndex=-1;
 for(int j=0;j<b;j++)
 { if(tempBlock2[j]>=process[i])
 { if(bestIndex==-1 || tempBlock2[j]<tempBlock2[bestIndex]) bestIndex=j;
 } }
 if(bestIndex!=-1)
 { allocation[i]=bestIndex;
 tempBlock2[bestIndex]-=process[i];
 cout<<"Process "<<i+1<<" -> Block "<<bestIndex+1<<endl;
 } else cout<<"Process "<<i+1<<" -> Not Allocated"<<endl;}
 // WORST FIT
 cout<<"\nWorst Fit Allocation\n";
 int tempBlock3[50];
 for(int i=0;i<b;i++) tempBlock3[i]=block[i];
 for(int i=0;i<p;i++)
 { allocation[i]=-1; int worstIndex=-1;
 for(int j=0;j<b;j++) {
 if(tempBlock3[j]>=process[i]){
 if(worstIndex==-1 || tempBlock3[j]>tempBlock3[worstIndex]) worstIndex=j;
 } }
 if(worstIndex!=-1) {
 allocation[i]=worstIndex; tempBlock3[worstIndex]-=process[i];
 cout<<"Process "<<i+1<<" -> Block "<<worstIndex+1<<endl;
 } else cout<<"Process "<<i+1<<" -> Not Allocated"<<endl; }
 // NEXT FIT
 cout<<"\nNext Fit Allocation\n"; int tempBlock4[50];
 for(int i=0;i<b;i++) tempBlock4[i]=block[i];
 int lastAllocated=0;
 for(int i=0;i<p;i++)
 { allocation[i]=-1;
 int count=0,j=lastAllocated;
 while(count<b)
 { if(tempBlock4[j]>=process[i])
 { allocation[i]=j;
 tempBlock4[j]-=process[i];
 lastAllocated=j;
 break; }
 j=(j+1)%b; count++; }
 if(allocation[i]!=-1) cout<<"Process "<<i+1<<" -> Block "<<allocation[i]+1<<endl;
 else cout<<"Process "<<i+1<<" -> Not Allocated"<<endl; } return 0;
