#include <iostream>
using namespace std;
int main(){
int pages[50], frame[10];
int n, f, pageFault = 0;
cout << "Enter number of pages: ";
cin >> n;
cout << "Enter page reference string:\n";
for(int i = 0; i < n; i++)
cin >> pages[i];
cout << "Enter number of frames: ";
cin >> f;
// initialize frames with -1
for(int i = 0; i < f; i++)
frame[i] = -1;
int index = 0;
for(int i = 0; i < n; i++)
{ bool found = false;
// check if page already exists
for(int j = 0; j < f; j++)
{ if(frame[j] == pages[i])
{ found = true; break; } }
// page fault
if(!found) {
frame[index] = pages[i];
index = (index + 1) % f;
pageFault++;
cout << "Frames: ";
for(int j = 0; j < f; j++)
cout << frame[j] << " ";
cout << endl; } }
cout << "\nTotal Page Faults = " << pageFault;
return 0; }
