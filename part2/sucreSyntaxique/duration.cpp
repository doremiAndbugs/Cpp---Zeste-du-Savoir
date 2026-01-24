#include <iostream>
#include <string>

struct Duration
{
  int seconds;
};


/**Return the duration ins econds
 *@return Duration in seconds
 */
int toSeconds(){
  return seconds;
}

/**converts the duration in minutes
 *
 *@return Duration in minutes and in seconds
 */
std::tuple<int,int> toMinutes(){
  int minutes=0;
  if(s<60){
    int duration= std::tuple {0, seconds};
  }else{
    minutes = seconds/60;
    seconds = seconds%60;
    int duration = std::tuple {minutes, s.seconds};
  }
  return duration;
}

/**Convers the duration in Hours (an minutes/seconds but optionnal)
 *
 *@return Duration in hours, minutes and seconds
 */
std::tuple<int,int,int> toHours(){
  int hours=0;
  if(s>=3600){
    hours = seconds/3600;
    seconds = seconds%3600;
  }
  int reste = this.toMinutes();
  int duration = std::tuples {hours, std::get<1>(this), std::get<2>(this)};
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
Duration opposite(){
  return {-seconds};
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
bool operator=!(Duration const & a, Duration const & b){
  return !(a==b=;
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
  bool operator>Duration const & a, Duration const & b){
  return !(a<b);
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
std::ostram & operator<<(std::ostream flux, Duration const & duration){
  std::tuples convert = duration.toHours();
  if(duration.seconds <0){
    convert = std::tuple(std::get<1>(hours),-std::get<2>(hours), -std::get<3>(hours));
  }
  return flux << std::get<1>(hours) << ":" << std::get<2>(hours) << "'" << std::get<3>(hours) << "\"" << std::endl;
}


