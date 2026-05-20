//scan
#include <iostream>
using namespace std;
int main() {
 int n, head, size, seek = 0;
 cout << "Enter number of requests: ";
 cin >> n;
 int req[n];
 cout << "Enter requests: ";
 for(int i=0;i<n;i++)
 cin >> req[i];
 cout << "Enter initial head: ";
 cin >> head;
 cout << "Enter disk size: ";
 cin >> size;
 // sorting
 for(int i=0;i<n-1;i++)
 for(int j=0;j<n-i-1;j++)
 if(req[j] > req[j+1]) {
 int t = req[j];
 req[j] = req[j+1];
 req[j+1] = t; }
 int pos = 0;
 while(pos < n && req[pos] < head)
 pos++;
 // move right
 for(int i=pos;i<n;i++) {
 seek += (head > req[i]) ?
 head-req[i] : req[i]-head;
 head = req[i]; }
 seek += (size-1) - head;
 head = size-1;
 // move left
 for(int i=pos-1;i>=0;i--) {
 seek += (head > req[i]) ?
head-req[i] : req[i]-head;
 head = req[i]; }
 cout << "Total Seek Time = "
<< seek; return 0; }
