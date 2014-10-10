#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int ret_sum(const vector<string>& list);

int main()
{
  ifstream infile("novel.txt");

  string cur_str;           //current string
  vector<string> word_list; //vector of string type to hold all the words

  if(infile.is_open())
  {
    //While we can still grab data AND we have less than 500 words in the list
    while(infile >> cur_str && word_list.size() < 500)
    {
      word_list.push_back(cur_str);
    }

    infile.close(); //close file we're working with

    //Call ret_sum function to get character count
    int num_char = ret_sum(word_list);

    cout << "Total number of characters in the " << word_list.size() << " words"
         << " grabbed from novel.txt: " << num_char << endl;
  }
  else
  {
    cout << "File could not be opened. Make sure that the filename and extension match the   following: "
         << "\"novel.txt\"\n";
  }

  system("pause");

  return 0;
}

int ret_sum(const vector<string>& list)
{
  int num_char = 0; //set up character count variable

  for(int i = 0; i < list.size(); ++i)
  {
    //num_char equals num_char plus the ith element in word_list's length
    num_char+=list[i].length();
  }

  return num_char;
}