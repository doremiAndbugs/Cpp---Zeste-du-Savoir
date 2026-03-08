#include <iostream>
#include <string>
#include <vector>


struct Artiste{
  std::string nom;
};

struct Album{
  std::string nom;
};

struct Morceau{
  std::string nom;
  Album album;
  Artiste artiste;
};

using Discographie = std::vector<Morceau>;

std::ostream & operator<<(std::ostream & sortie, Artiste const & artiste){
  
}
std::ostream & operator<<(std::ostream & sortie, Album const & album);
std::ostream & operator<<(std::ostream & sortie, Morceau const & morceau);
std::istream & operator>>(std::istream & entree, Morceau & morceau);

