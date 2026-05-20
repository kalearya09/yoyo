#include<iostream>
using namespace std;
int main()
{ int n,f,p[50],fr[10],time[10],pf=0,cnt=0;
 cin>>n;
 for(int i=0;i<n;i++) cin>>p[i];
 cin>>f;
 for(int i=0;i<f;i++)
 { fr[i]=-1;
 time[i]=0; }
 for(int i=0;i<n;i++)
 { bool found=false;
 for(int j=0;j<f;j++)
 { if(fr[j]==p[i])
 { cnt++;
 time[j]=cnt;
 found=true; } }
 if(!found)
 { int pos=0;
 for(int j=1;j<f;j++)
 if(time[j]<time[pos]) pos=j;
 cnt++;
 fr[pos]=p[i];
 time[pos]=cnt;
 pf++; } }
 cout<<"Page Faults = "<<pf;
 return 0; }
 //optimal
 #include<iostream>
using namespace std;
int main()
{ int n,f,p[50],fr[10],pf=0;
 cin>>n;
 for(int i=0;i<n;i++) cin>>p[i];
 cin>>f;
 for(int i=0;i<f;i++) fr[i]=-1;
 for(int i=0;i<n;i++)
 { bool found=false;
 for(int j=0;j<f;j++)
 if(fr[j]==p[i]) found=true;
 if(!found)
 { int pos=0,far=-1;
 for(int j=0;j<f;j++)
 { if(fr[j]==-1)
 {pos=j;
 break; }
 int k;
 for(k=i+1;k<n;k++)
 if(fr[j]==p[k]) break;
 if(k>far)
 { far=k;
 pos=j; } }
 fr[pos]=p[i];
 pf++; } }
 cout<<"Page Faults = "<<pf;
 return 0; }
