#include <iostream>
using namespace std;
int main() {
 int n, m;
 //resouces and process input
 cout << "Enter number of processes: ";
 cin >> n;
 cout << "Enter number of resources: ";
 cin >> m;
 //matrix of alloc max & available
 int alloc[n][m], max[n][m], avail[m];
 //alocation matrix
 cout << "\nEnter Allocation Matrix:\n";
 for(int i = 0; i < n; i++)
 for(int j = 0; j < m; j++)
 cin >> alloc[i][j];
 //max
 cout << "\nEnter Max Matrix:\n";
 for(int i = 0; i < n; i++)
 for(int j = 0; j < m; j++)
 cin >> max[i][j];
 //availavble
 cout << "\nEnter Available Resources:\n";
 for(int j = 0; j < m; j++)
 cin >> avail[j];
 //need matrix
 int need[n][m];
 for(int i = 0; i < n; i++)
{ for(int j = 0; j < m; j++)
 { need[i][j] = max[i][j] - alloc[i][j]; }
for(int j=0;j<m;j++)
 cout << need[i][j] << " ";
cout << endl; }
 bool finish[n] = {false}; //to check if process is complete
 int safeSeq[n]; //safesequence storage
 int count = 0; //to count no of completed process
 //loop runs for all process-> complete
 while(count < n) {
 bool found = false; //to check proess not complete
 for(int i = 0; i < n; i++) {
 if(!finish[i]) {
 int j;
 for(j = 0; j < m; j++) {
 if(need[i][j] > avail[j])
 break;
 }
 if(j == m) { //all resources r satisfied
 //to rerelease resources
 for(int k = 0; k < m; k++)
 avail[k] += alloc[i][k];
 //to add process to safe sequence
 safeSeq[count++] = i;
 finish[i] = true;
 found = true;
 } } }
 // deadlock possibility
 if(!found) {
 cout << "\nSystem is NOT in safe state (Deadlock possible)\n";
 return 0; } }
 // safe sequence possibility
 cout << "\nSystem is in SAFE state.\nSafe Sequence: ";
 for(int i = 0; i < n; i++)
 cout << "P" << safeSeq[i] << " ";
 cout << endl; return
