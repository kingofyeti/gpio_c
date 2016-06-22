#ifndef SRC_GPIO_WRAPPER_H_
#define SRC_GPIO_WRAPPER_H_

#include <gpio.h>

#include <string>
#include <vector>

class GPIO_Wrapper {
  public:
    static GPIO gpio_1;
    static GPIO gpio_2;
    static GPIO gpio_3;
    static GPIO gpio_4;
    const static int id_list[];
    const static int cycle[];

    GPIO_Wrapper();
    ~GPIO_Wrapper();

    void init_GPIO_list();
    void run();
};

#endif
