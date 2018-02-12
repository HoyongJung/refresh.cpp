#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<string> names;
int main(int argc, char *argv[]) {
  cout << "Hello World!" << endl;
  cout << "argc " << argc << " argv[0] " << argv[0] << " argv[1]= " << argv[1] << endl;
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <filename>" << endl;
  }
  else {
    ifstream fileHandle(argv[1]);
    if (!fileHandle.is_open()) {
      cout << "Could not open file" << endl;
    }
    else {
      string name;
      int age;
      while (fileHandle >> name >> age) {
        names.push_back(name);
        cout << "Name " << name << "\tAge " << age << endl;
      }
    }
  }
  sort(names.begin(), names.end());
  ofstream outHandle("sorted.txt");
    for(vector<string>::iterator it=names.begin(); it!=names.end(); it++) { //iterator that doesn't care of container's shape
          cout << *it<<endl;
          outHandle << *it <<endl;
    }
}
