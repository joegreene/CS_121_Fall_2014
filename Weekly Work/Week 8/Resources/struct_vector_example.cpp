#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Struct for movies
struct Movie
{
  string title;
  double rating;
  double prod_cost;
  string rel_date; //this can be improved by using a nested struct, where "Date" is that struct
  //etc.
};

//Debug function to print each movie out
void print_movie(const Movie& m)
{
  //cout << "Movie Information:" << endl;
  //cout << "------------------" << endl;
  cout << "Title: " << m.title << endl;
  cout << "Rating: " << m.rating << endl;
  cout << "Production Cost: " << m.prod_cost << endl;
  cout << "Date Released: " << m.rel_date << endl;
}

int main()
{
  //Items required for vector option
  vector<Movie> movie_list; //vector of Movie
  Movie m;                  //temporary variable for pushing back to vector
  bool grab_input = true;   //boolean to track if input should still grab input from console

  //Initialization loop; Prompt and grab data; while grab input
  do
  {
    cout << "Enter the movie title (type 'EXIT' to exit prompt): ";
    getline(cin, m.title);

    if(m.title == "EXIT")
    {
      grab_input = false;
    }
    else //continue loop
    {
      cout << "Enter the movie's rating: ";
      cin >> m.rating;

      cout << "Enter the movie's production cost: ";
      cin >> m.prod_cost;

      cout << "Enter the movie's release date: ";
      cin >> m.rel_date;
    
      //Afterwards, add a CURRENT COPY of m to movie_list
      movie_list.push_back(m);

      //If we plan to mix "getline" and "cin >> ...", we need the following:
      cin.ignore(1); //ignore '\n' since cin ignores whitespace but getline does not, 
                     //meaning '\n' still exists at the end after cin >> m.rel_date is called
    }
  }while(grab_input);

  //Debug code
  cout << "Movie List Information:" << endl;
  cout << "----------------------" << endl;

  //If the movie list is not empty, print the list
  if(!movie_list.empty())
  {
    for(int i = 0; i < movie_list.size(); ++i)
    {
      print_movie(movie_list[i]);
    }
  }
  else //otherwise, tell the user that the list is empty
  {
    cout << "Movie list is empty! Ending program..." << endl << endl;
  }
  system("pause");

  return 0;
}