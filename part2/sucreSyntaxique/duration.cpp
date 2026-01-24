#include <iostream>
#include <string>

struct Duration
{
  int seconds;
};

int toSeconds(){
  return seconds;
}

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
