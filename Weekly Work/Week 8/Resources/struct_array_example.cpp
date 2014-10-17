#include <iostream>
#include <string>

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
  //Items required for array option
  const int LIST_SIZE = 5;
  Movie movie_list[LIST_SIZE]; //array of Movie

  //Initialization loop; Prompt and grab data (I set the loop to 2 for debugging purposes)
  for(int i = 0; i < 2; ++i)
  {
    cout << "Enter the movie title: ";
    getline(cin, movie_list[i].title);

    cout << "Enter the movie's rating: ";
    cin >> movie_list[i].rating;

    cout << "Enter the movie's production cost: ";
    cin >> movie_list[i].prod_cost;

    cout << "Enter the movie's release date: ";
    cin >> movie_list[i].rel_date;
    
    //If we plan to mix "getline" and "cin >> ...", we need the following:
    cin.ignore(1); //ignore '\n' since cin ignores whitespace but getline does not, 
                   //meaning '\n' still exists at the end after cin >> m.rel_date is called
  }

  //Debug code (changed the number to 2 so I didn't need to enter 5 movies every time)
  cout << "Movie List Information:" << endl;
  cout << "----------------------" << endl;

  for(int i = 0; i < 2; ++i)
  {
    print_movie(movie_list[i]);
  }

  system("pause");

  return 0;
}