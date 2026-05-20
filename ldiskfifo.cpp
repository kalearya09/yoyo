//fifo
#include <iostream>
#include <cmath>
using namespace std;
int main() {
 int n, head;
 cout << "Enter number of requests: ";
 cin >> n;
 int req[n];
 cout << "Enter request sequence:\n";
 for(int i = 0; i < n; i++)
 cin >> req[i];
 cout << "Enter initial head position: ";
 cin >> head;
 int seek = 0;
 for(int i = 0; i < n; i++) {
 seek += abs(head - req[i]);
 head = req[i]; }
 cout << "Total Seek Time (FCFS): " << seek;
return 0; }
