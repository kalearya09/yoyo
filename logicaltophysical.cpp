#include <iostream>
using namespace std;
int main()
{ int logicalAddress, pageSize, numPages;
 cout << "Enter page size: ";
 cin >> pageSize;
 cout << "Enter number of pages: ";
 cin >> numPages;
 int pageTable[numPages];
 cout << "Enter page table (Frame numbers):\n";
 for(int i = 0; i < numPages; i++)
 { cout << "Page " << i << " -> Frame: ";
 cin >> pageTable[i]; }
 cout << "Enter logical address: ";
 cin >> logicalAddress;
 int pageNumber = logicalAddress / pageSize;
 int offset = logicalAddress % pageSize;
 if(pageNumber >= numPages)
 { cout << "Invalid Logical Address!";}
 else {
 int frameNumber = pageTable[pageNumber];
 int physicalAddress = frameNumber * pageSize + offset;
 cout << "\nPage Number: " << pageNumber;
 cout << "\nOffset: " << offset;
 cout << "\nFrame Number: " << frameNumber;
 cout << "\nPhysical Address: " << physicalAddress;
 } return 0; }
