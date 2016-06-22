#include "gpio_wrapper.h"

#include "unistd.h"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;

const int GPIO_Wrapper::id_list[] = {204,205,236,237};
const int GPIO_Wrapper::cycle[] = {1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0};
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
    gpio_1.SetDirection(1);
    gpio_2.SetDirection(1);
    gpio_3.SetDirection(1);
    gpio_4.SetDirection(1);
}

void GPIO_Wrapper::run(){
  while(true){
    for(int i=0;i<4;i++){
      gpio_1.SetValue(4*i);
      gpio_2.SetValue(4*i+1);
      gpio_3.SetValue(4*i+2);
      gpio_4.SetValue(4*i+3);
      usleep(10); 
    }
  }
}
