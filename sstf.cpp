//sstf
#include <iostream>
#include <cmath>
using namespace std;
int main() {
 int n, head;
 cout << "Enter number of requests: ";
 cin >> n;
 int req[n], completed[n];
 cout << "Enter request sequence:\n";
 for(int i = 0; i < n; i++) {
 cin >> req[i];
 completed[i] = 0; }
 cout << "Enter initial head position: ";
 cin >> head;
 int seek = 0;
 for(int i = 0; i < n; i++) {
 int min = 1e9, index = -1;
 for(int j = 0; j < n; j++) {
 if(!completed[j]) {
 int dist = abs(head - req[j]);
 if(dist < min) {
 min = dist;
 index = j; } } }
 seek += min;
 head = req[index];
 completed[index] = 1; }
 cout << "Total Seek Time (SSTF): " << seek;
 return 0;
}
