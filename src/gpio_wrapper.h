#ifndef GPIO_WRAPPER_H_
#define GPIO_WRAPPER_H_

#include "gpio.h"

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
    const static int one_round_step;

    const static int high_speed;
    const static int mid_speed;
    const static int low_speed;
    const static int one_sec;

    GPIO_Wrapper();
    ~GPIO_Wrapper();

    void init_GPIO_list();

    // first argument: round
    // second argument: speed  1: low 2: mid 3:high
    void run(float round,int speed);
    void run_one_step(int speed);
    void reset();

};

#endif
