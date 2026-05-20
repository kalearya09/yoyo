#include <iostream>
#include <cmath>
using namespace std;
struct Block {
 int size;
 bool free;
};
int main() {
 int memorySize, n;
 cout << "Enter total memory size (power of 2): ";
 cin >> memorySize;
 cout << "Enter number of processes: ";
 cin >> n;
 int process[n];
 cout << "Enter process sizes:\n";
 for(int i = 0; i < n; i++)
 cin >> process[i];
 Block blocks[100];
 // initially one free block
 int blockCount = 1;
 blocks[0].size = memorySize;
 blocks[0].free = true;
 for(int i = 0; i < n; i++) {
 int required = 1;
 // find nearest power of 2
 while(required < process[i])
 required *= 2;
 bool allocated = false;
 for(int j = 0; j < blockCount; j++) {
 // split until suitable size
 while(blocks[j].size / 2 >= required && blocks[j].free) {
 blocks[blockCount].size = blocks[j].size / 2;
 blocks[blockCount].free = true;
 blocks[j].size /= 2;
 blockCount++; }
 // allocate block
 if(blocks[j].free && blocks[j].size >= required) {
 blocks[j].free = false;
 cout << "\nProcess " << i + 1
 << " of size " << process[i]
 << " allocated in block size "
 << blocks[j].size;
 cout << "\nInternal Fragmentation = "
 << blocks[j].size - process[i] << endl;
 allocated = true;
 break; } }
 if(!allocated) {
 cout << "\nProcess " << i + 1
 << " cannot be allocated.\n"; } }
 // memory status
 cout << "\n\nMemory Blocks Status:\n";
 for(int i = 0; i < blockCount; i++) {
 cout << "Block " << i + 1
 << " Size: " << blocks[i].size
 << " -> ";
 if(blocks[i].free)
 cout << "Free";
 else
 cout << "Allocated";
 cout << endl; }
 return 0;}
