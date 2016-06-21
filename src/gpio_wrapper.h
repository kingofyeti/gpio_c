#ifndef SRC_GPIO_WRAPPER_H_
#define SRC_GPIO_WRAPPER_H_

#include <gpio.h>

#include <string>
#include <vector>

class GPIO_Wrapper {
  public:
    GPIO_Wrapper();
    ~GPIO_Wrapper();

    void run();

  private:
    const static int id_list[];
    const static int cycle[];
    std::vector<GPIO> gpio_list;

    void init_GPIO_list();
};

#endif
