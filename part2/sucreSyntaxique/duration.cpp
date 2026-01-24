#include <iostream>
#include <string>

struct Duration
{
  int seconds;
};

std::tuple<int> secondToMinutes(Duration & s){
  int minutes=0;
  if(s<60){
    int duration= std::tuple {0, s.seconds};
  }else{
    while(s>60){
    s.seconds = s.seconds-60;
    minutes++;
    }
    int duration = std::tuple {minutes, s.seconds};
  }
  return duration;
}
