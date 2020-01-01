#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
using namespace std;
class HashTable {
	//linklist to store hash_list
  list<int> *hash_list;
  //size of Hash table
  int size;
// introduction to algorithms 3rd editon
 //CHAINED-HASH-INSERT.T;x/
//1 insert x at the head of list T Œh.x:key/􏰀
//CHAINED-HASH-SEARCH.T;k/
//1 search for an element with key k in list T Œh.k/􏰀
//CHAINED-HASH-DELETE.T;x/
//1 delete x from the list T Œh.x:key/􏰀
    
    
public:
  HashTable(int size);
    
  int hashFunction(int k);
    
  void insert(int k);
    
  int deleteValue(int k);
    
  int search(int k);
    
  void output();
};

HashTable::HashTable(int size) {
	//initilize size
  this->size = size;
  hash_list = new list<int>[size];
}

// hash function.

int HashTable::hashFunction(int k)
{
	//hash formula Percent indicated mod then size
	return (k) % size; 
} 
// HASH-INSERT.T;k/ 1iD0 the value indicated
//2 3 4 5 6 7 8 9
//repeat
//j D h.k;i/
//if T Œj 􏰀 == NIL TŒj􏰀 D k
//return j else i D i C 1
//untili==m
//error “hash table overflow”
void HashTable::insert(int k) {
  int hash_value = hashFunction(k);
  hash_list[hash_value].push_front(k);
}

// Now we can delete the value indicated
int HashTable::deleteValue(int k) {
  int hash = hashFunction(k);
  list<int>::iterator iter;
  //iterate over hashtable
  for (iter = hash_list[hash].begin(); iter != hash_list[hash].end(); ++iter) {
    if (*iter == k) {
      hash_list[hash].erase(iter);
      return 0;
    }
  }
  return -1;
}

int HashTable::search(int k) {
	//get hash value
	int hash_value = hashFunction(k);
  list<int>::iterator iter;
  //iterate over hash table
  for (iter = hash_list[hash_value].begin(); iter != hash_list[hash_value].end(); ++iter) {
    if (*iter == k) {
      return distance(hash_list[hash_value].begin(), iter);
    }
  }
  //return -1 if not found
  return -1;
}
// output the value we need
void HashTable::output() {
	for (int i = 0; i < size; i++) {
		cout << i << ":";
		list<int>::iterator iter;
		for (iter = hash_list[i].begin(); iter != hash_list[i].end(); ++iter) {
			cout << *iter << "->";
		}
		cout << ";" << endl;
	}
}
// search helper
void search(HashTable &hash_table, int k) {
  int id = hash_table.search(k);
  if (id == -1) {
	  cout << k << ":NOT_FOUND;\n";
  } else {
    cout << k << ":FOUND_AT" << hash_table.hashFunction(k) << "," << id << ";" << endl;
  }
}

void inputProcessing(HashTable &hash_table, string str) {
  char *c = &str[0];
  if (str[0] == 'i')
  {
	  hash_table.insert(atoi(c + 1));
  }
  else if (str[0] == 's')
  {
	  search(hash_table, atoi(c + 1));
  }
  else if (str[0] == 'd')
  {
	  int value = atoi(c + 1);
	  if (hash_table.deleteValue(value) == 0) {
		  cout << value << ":DELETED;" << endl;
	  }
	  else {
		  cout << value << ":DELETE_FAILED;" << endl;
	  }
  }
  else if (str[0] == 'o')
  {
	  hash_table.output();
  }
}
// main function needed to input our info and run
int main() {
  int size;
    // indicate the size of the int
  
    cin >> size;
    // take in input for size
  HashTable table(size);
    
  string instr;
    
  while (instr.compare("e") != 0) {
      
    cin >> instr; // takes in the cin instr;
      
    inputProcessing(table, instr);
      
  }
  //output(hTable);
  return 0;
}
