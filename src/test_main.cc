#include "gpio_wrapper.h"

#include <cstdio>

using namespace std;

int main(){
  GPIO_Wrapper gpio_wrapper; 

  // first argument: round
  // second argument: speed  1: low 2: mid 3:high
  gpio_wrapper.run(0.5,1);
}
