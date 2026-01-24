#include <iostream>
#include <string>

struct Fraction
{
    int numerateur;
    int denominateur;
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

  RETURN { NUMERATEUR, DENOMINATEUR };
}

int main()
{
    Fraction const un_demi { 1, 2 };
    Fraction const trois_quarts { 3, 4 };
    Fraction const deux_huitièmes { 2, 8 };

    Fraction const resultat { un_demi / trois_quarts * deux_huitièmes };
    std::cout << "1/2 / 3/4 * 2/8 font " << resultat.numerateur << "/" << resultat.denominateur << std::endl;

    return 0;
}
