#include "AVLNode.h"
#include "HashTable.h"
#include <string>
using namespace std;

bool ghiFileSach(string tenFile, AVLNodeptr root);
bool docFileSach(string tenFile, AVLNodeptr& root);

bool ghiFileDocGia(string tenFile, HashNodeptr hashTable[SIZE]);
bool docFileDocGia(string tenFile, HashNodeptr hashTable[SIZE]);