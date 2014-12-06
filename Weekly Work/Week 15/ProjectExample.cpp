#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  cout << "Listing all arguments used in the program:" << endl
       << "------------------------------------------" << endl;

  for(int i = 0; i < argc; ++i)
  {
    cout << "Argument " << i << ": " << argv[i] << endl;
  }

  system("pause");

  return 0;
}