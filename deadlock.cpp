#include <iostream>
using namespace std;
int main(){
int n, m;
cout << "Enter number of processes: ";
 cin >> n;
 cout << "Enter number of resource types: ";
 cin >> m;
 int allocation[n][m], request[n][m], available[m]; cout << "\nEnter Allocation Matrix:\n";
 for(int i = 0; i < n; i++)
 { for(int j = 0; j < m; j++)
 { cin >> allocation[i][j]; } }
 cout << "\nEnter Request Matrix:\n";
 for(int i = 0; i < n; i++)
 { for(int j = 0; j < m; j++)
 { cin >> request[i][j]; } }
 cout << "\nEnter Available Resources:\n";
 for(int i = 0; i < m; i++)
 { cin >> available[i]; }
 int work[m] , bool finish[n];
 // Step 1: Initialize
 for(int i = 0; i < m; i++)
 { work[i] = available[i]; }
 for(int i = 0; i < n; i++)
 { finish[i] = false; }
 // Step 2 & 3
 bool found;
 do {
 found = false;
 for(int i = 0; i < n; i++)
 { if(finish[i] == false)
 { bool possible = true;
 for(int j = 0; j < m; j++)
 { if(request[i][j] > work[j])
 { possible = false;
 break; } }
 if(possible)
 { for(int j = 0; j < m; j++)
 { work[j] += allocation[i][j]; }
 finish[i] = true;
 found = true; } } } }
while(found);
 // Step 4: Check deadlock
 bool deadlock = false;
 cout << "\nDeadlocked Processes: ";
 for(int i = 0; i < n; i++)
 {if(finish[i] == false)
 { cout << "P" << i << " ";
 deadlock = true; } }
 if(deadlock == false)
 { cout << "No Deadlock"; }
 return 0;
