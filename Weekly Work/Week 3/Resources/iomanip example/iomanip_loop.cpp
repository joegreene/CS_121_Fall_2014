/*
  NAME: Joe Greene
  Program: Item List Print
  Purpose: To print the number of items we currently have in the listing
  Notes:
    - This exercise shows how to properly use iomanip (with arrays)
    - Other topics shown: constant variables, counters, string, arrays, 
      for loops, parallel arrays, partially-filled arrays
    - name_list and price_list are parallel arrays. This means that their 
      corresponding indexes/cells relate to one another in some significant
      way.
    - With the test data, there are currently 4 of 5 total amount of items. 
      Visually, the arrays (at the start) look like this (indexes on top):
                     0    1    2    3    4
      name_list =  [   ][   ][   ][   ][   ]
      price_list = [   ][   ][   ][   ][   ]

      After plugging in the test data, the arrays are (with index on top):
                        0         1        2         3      4
      name_list =  ["Toy Car"]["Doll"]["Pillow"]["Sponge"][   ]
      price_list = [  1.99   ][ 3.99 ][ 16.99  ][  1.50  ][   ]

      Noting that the last cells in each array is empty, so each 
      array is called a partially-filled array.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  int item_count = 0;          //the true number of items in the list (counter)
  const int ITEM_CAP = 5;      //limit on how many items there can be in total
  string name_list[ITEM_CAP];  //list of item names
  double price_list[ITEM_CAP]; //list of item prices

  //----------------TEST DATA----------------
  //First item; index 0 (start from 0)
  name_list[0] = "Toy car";
  price_list[0] = 1.99;
  item_count++; //increment item_count (because we added an item)

  //Second item; index 1
  name_list[1] = "Doll";
  price_list[1] = 3.99;
  item_count++; //increment item_count (because we added an item)

  //Third item; index 2
  name_list[2] = "Pillow";
  price_list[2] = 16.99;
  item_count++; //increment item_count (because we added an item)

  //Fourth item; index 3
  name_list[3] = "Sponge";
  price_list[3] = 1.50;
  item_count++; //increment item_count (because we added an item)

  //If you want, include a fifth item here (make sure to use index = 4 and increment!)

  //-------------END OF TEST DATA------------

  //To make life easier, set the widths of each column as constant integers (values are just a rough guess)
  const int ITEM_NAME_WIDTH = 10; //this includes the item name length and the spaces between ITEMS and PRICES
  const int PRICE_WIDTH = 7;      //how long we think the prices will be at maximum
  
  //Print the header; NOTE: setfill is ' ' on default and make sure the output (from now on) is left-justified
  cout << left << setw(ITEM_NAME_WIDTH) << "ITEMS" << "PRICES" << endl; //the number is just a guess on 
  
  //NOTE: setw doesn't work unless you print a character. I chose '-' and subtracted a dash from setw to compensate
  cout << setfill('-') << setw(ITEM_NAME_WIDTH + PRICE_WIDTH - 1) << "-" << endl; //set the dashes length to cover both item names and prices
  
  //Reset setfill for printing each name and price, and setprecision (using fixed notation to round from the decimal place)
  cout << setfill(' ') << fixed << setprecision(2);
  
  //Loop through the list until you print the last item
  for(int i = 0; i < item_count; ++i)
  {
    //print the name (setw covers spaces inbetween), dollar sign, then price (and endl after)
    cout << setw(ITEM_NAME_WIDTH) << name_list[i] << "$" << price_list[i] << endl;
  }

  //Similar to "system("pause");" except the following code works on more systems than just Windows
  cout << "\nPress ENTER to exit program...";
  cin.ignore();

  return 0;
}