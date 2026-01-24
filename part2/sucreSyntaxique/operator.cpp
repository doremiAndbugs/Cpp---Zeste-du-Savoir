#include <iostream>
#include <string>
#include <cmath>

struct Fraction
{
    int numerateur;
    int denominateur;

  Fraction(int num, int den) : numerateur{num}, denominateur{den}{
    if(den == 0){
      throw std::invalid_argument("the denominator can't be equal to 0");
    };
  }
  regler();

  void regler(){
    if(denominateur< 0){
      numerateur = -numerateur;
      denominateur = -denominateur;
    };
};

// Ça ressemble à quelque chose de connu, hein ?
Fraction operator+(Fraction const & a, Fraction const & b)
{
    int numerateur { a.numerateur * b.denominateur + b.numerateur * a.denominateur };
    int denominateur { a.denominateur * b.denominateur };

    return { numerateur, denominateur };
}

Fraction operator-(Fraction const & a, Fraction const & b)
{
    int numerateur { a.numerateur * b.denominateur - b.numerateur * a.denominateur };
    int denominateur { a.denominateur * b.denominateur };

    return { numerateur, denominateur };
}

Fraction operator/(Fraction const & a, Fraction const & b)
{
  int numerateur { a.numerateur * b.denominateur };
  int denominateur { a.denominateur * b.numerateur};

  return { numerateur, denominateur }; 
}


Fraction operator*(Fraction const & a, Fraction const & b)
{
  int numerateur { a.numerateur * b.numerateur };
  int denominateur { a.denominateur * b.denominateur};
  
  return { numerateur, denominateur };
}

Fraction Reverse(Fraction const & a){
  return {a.denominateur, a.numerateur};
}

Fraction opposite(Fraction const & a){
  return {-a.numerateur), a.denominateur};
}

std::ostream & operator<<(std::ostream & flux, Fraction const & fraction)
{
    return flux << fraction.numerateur << "/" << fraction.denominateur;
}

int main()
{
    Fraction const trois_quarts { 3, 4 };
    Fraction const deux_huitièmes { 2, 8 };
    Fraction const un_demi {-1, -2};
    Fraction const moins_un_demi {1,-2};

    try{
      Fraction const dividesBy0 {3, 0};
    } catch ( std::invalid_argument const & e){
      std::cerr << "Error : " << e.what() << std::endl;
    }
    std::cout << "The reverse of 1/-2 is "<< Reverse(moins_un_demi) << std::endl;
    std::cout << "The opposite of -1/-2 is "<< opposite(un_demi)<<std::endl; 
    
    std::cout << "1/2 / 3/4 * 2/8 font " << un_demi/trois_quarts*deux_huitièmes  << std::endl;

    return 0;
};}
