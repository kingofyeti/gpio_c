#include "gpio_wrapper.h"

#include "unistd.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::logic_error;
using std::runtime_error;

const int GPIO_Wrapper::id_list[] = {2,3,4,14};
const int GPIO_Wrapper::cycle[] = {1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0};
const int GPIO_Wrapper::one_round_time = 2500;
const int GPIO_Wrapper::high_speed = 6000;
const int GPIO_Wrapper::mid_speed = 8000;
const int GPIO_Wrapper::low_speed = 10000;

GPIO GPIO_Wrapper::gpio_1(id_list[0]);
GPIO GPIO_Wrapper::gpio_2(id_list[1]);
GPIO GPIO_Wrapper::gpio_3(id_list[2]);
GPIO GPIO_Wrapper::gpio_4(id_list[3]);

GPIO_Wrapper::GPIO_Wrapper(){
  init_GPIO_list();
}


GPIO_Wrapper::~GPIO_Wrapper(){
}

void GPIO_Wrapper::init_GPIO_list(){
    // Set 1 as GPIO output
    gpio_1.SetDirection(1);
    gpio_2.SetDirection(1);
    gpio_3.SetDirection(1);
    gpio_4.SetDirection(1);
}

void GPIO_Wrapper::run(float round,int speed){
  int cur_speed = 0;
  switch(speed){
    case 1:
      cur_speed = low_speed;
      break;
    case 2:
      cur_speed = mid_speed;
      break;
    case 3:
      cur_speed = high_speed;
      break;
    default :
      throw logic_error("Invalid speed string: It should be 1/2/3(low,mid,high)"); 
  }
  int total_round = int(one_round_time * round);
  while(total_round>0){
    for(int i=0;i<4;i++){
      gpio_1.SetValue(cycle[4*i]);
      gpio_2.SetValue(cycle[4*i+1]);
      gpio_3.SetValue(cycle[4*i+2]);
      gpio_4.SetValue(cycle[4*i+3]);
      usleep(cur_speed); 
    }
    total_round--;
  }
  reset();
}

void GPIO_Wrapper::reset(){
      gpio_1.SetValue(0);
      gpio_2.SetValue(0);
      gpio_3.SetValue(0);
      gpio_4.SetValue(0);
}
