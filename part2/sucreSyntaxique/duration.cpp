#include <iostream>
#include <string>
#include <tuple>

struct Duration
{
  int seconds;
};


/**Return the duration ins econds
 *@return Duration in seconds
 */
int toSeconds(Duration d){
  return d.seconds;
}

/**converts the duration in minutes
 *
 *@return Duration in minutes and in seconds
 */
std::tuple<int,int> toMinutes(Duration d){
  int minutes=0;
  int seconds = 0;
  std::tuple<int,int> duration;
  if(d.seconds<60){
    duration= std::tuple {0, d.seconds};
  }else{
    minutes = d.seconds/60;
    seconds = d.seconds%60;
    duration = std::tuple {minutes, d.seconds};
  }
  return duration;
}

/**Convers the duration in Hours (an minutes/seconds but optionnal)
 *
 *@return Duration in hours, minutes and seconds
 */
std::tuple<int,int,int> toHours(Duration d){
  int hours=0;
  std::tuple<int,int,int> duration;
  if(d.seconds>=3600){
    hours = d.seconds/3600;
    d.seconds = d.seconds%3600;
  }
  std::tuple<int,int> reste = toMinutes(d);
  duration = std::tuple  {hours, std::get<0>(reste),std::get<1>(reste)};
  return duration;
}

/**Adds two durations.
 *
 *@param a first duration
 *@parma b second duration
 *@return sum of two duration
 */
Duration operator+(Duration const & a, Duration const & b){
  Duration sum { a.seconds + b.seconds};
  return sum;
}

/**substract two Duration.
 *
 *@param a first duration
 *@parma b second duration
 *@return substraction of two duration
 */
Duration operator-(Duration const & a, Duration const & b){
  Duration sub { a.seconds - b.seconds};
  return sub;
}

/**@return the opposite of the duration
 */
Duration opposite(Duration d){
  return {-d.seconds};
}

/**Checks if two durations are equal.
 *@param a first duration
 *@parma b second duration
 *@return true if durations are equal, false otherwise.
 */
bool operator==(Duration const & a, Duration const & b){
  return a.seconds == b.seconds;
}


/**Checks if two durations are different.
 *@param a first duration
 *@parma b second duration
 *@return true if durations are different, false otherwise
 */
bool operator!=(Duration const & a, Duration const & b){
  return !(a==b);
}

    
/**Checks if the first duration is smaller than the seconde.
 *@param a first duration
 *@parma b second duration
 *@return true if a smaller than b , false otherwise
 */
bool operator<(Duration const & a, Duration const & b){
  return a.seconds < b.seconds;
}

  /**Checks if the first duration is greater than the second.
 *@param a first duration
 *@parma b second duration
 *@return true if a greater than b , false otherwise
 */
  bool operator>(Duration const& a, Duration const & b){
    return !(a<b) && !(a==b);
}

 /**Checks if the first duration is smaller or equal than the second.
 *@param a first duration
 *@parma b second duration
 *@return true if a smaller or equal than b , false otherwise.
 */
 bool operator<=(Duration const & a,Duration const & b){
  return (a<b) || (a==b);
}


 /**Checks if the first duration is greater or equal than the second.
 *@param a first duration
 *@parma b second duration
 *@return true if a gerater or equal than b , false otherwise.
 */
 bool operator>=(Duration const & a,Duration const & b){
  return (a>b) || (a==b);
}

/**Outputs a duration to an output stream in H::mm's" format
 *
 *The sign of the duration si placed before th houts.
 *Example : -2:05'30" for a negative duration fo 2 hours, 5 minutes , 30 seconds
 *
 *@param flux Output stream
 *@param the duration
 *@return the output stream
 */
std::ostream& operator<<(std::ostream& flux,Duration const & duration){
  std::tuple<int,int,int> hour = toHours(duration);
  int hours = std::get<0>(hour);
  int min  = std::get<1>(hour);
  int sec = std::get<2>(hour);
  if(duration.seconds <0){
    hours = -hours;
    min = -min;
    sec = -sec;
  }
  return flux <<hours  << ":" << min << "'" << sec << "\"" << std::endl;
}




int main(){
  Duration const hourAndAHalf {3630};
  Duration const halfHour {1800};
  std::cout << "An hour and a half in seconds : " <<toSeconds(hourAndAHalf)<<std::endl;
  std::tuple<int,int> min = toMinutes(hourAndAHalf);
  
  std::cout << "An hour and a half in minutes : " << std::get<0>(min)  << "minutes and"<< std::get<1>(min)<< "seconds" <<std::endl;
  
  std::tuple<int,int,int> hour = toHours(hourAndAHalf);
  std::cout << "An hour and a half in hour : "<<std::get<0>(hour) << "hour and"  << std::get<1>(hour)<<"minutes and"<<std::get<2>(hour)<<"seconds" <<std::endl;
 
  std::cout << "3630+1800=: "<<(hourAndAHalf + halfHour)<<std::endl;
  std::cout << "3630-1800=: "<<(hourAndAHalf - halfHour)<<std::endl;

  std::cout << "the opposite of 1800 is : "<<opposite(halfHour)<<std::endl;
  
  std::cout << std::boolalpha;
  std::cout << "Is 3630 seconds smaller than 1800 seconds : " <<(hourAndAHalf < halfHour) << std::endl;
  std::cout << "Is 3630 seconds greater than 1800 seconds : " <<(hourAndAHalf > halfHour) << std::endl;
  std::cout << "Is 3630 seconds equal to 1800 seconds : " <<(hourAndAHalf == halfHour)<< std::endl;
  std::cout << "Is 3630 seconds differents than 1800 seconds : " <<(hourAndAHalf!=halfHour) << std::endl;

  return 0;
}
  


 
