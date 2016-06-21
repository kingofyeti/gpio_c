#include "gpio_wrapper.h"

#include "unistd.h"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;

const int GPIO_Wrapper::id_list = {204,205,236,237};
const int GPIO_Wrapper::cycle = {1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0};

GPIO_Wrapper::GPIO_Wrapper(){
  init_GPIO_list();
}


GPIO_Wrapper::~GPIO_Wrapper(){
}

void GPIO_Wrapper::init_GPIO_list(){
  for(int i=0;i<4;i++){
    GPIO::GPIO gpio(id_list[i]);
    gpio.SetDirection(1);
    gpio_list.push_back(gpio);
  }
}

void GPIO_Wrapper::run(){
  while(true){
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        gpio_list[i].SetValue(i*j);
      } 
      usleep(10); 
    }
  }
}
