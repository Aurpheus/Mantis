//
// Created by Baptiste on 15/12/2023.
//

#include "test_run_class.h"

//main for tests
int main() {
    //test mantis
    auto *m1 = new Mantis();
    auto *t1 = new Terrarium(50, m1);

    for (int i = 0; i < 9000; i++) {
        t1->hour_pass();
        std::cout << "Humidity: " << t1->getHumidity_prct() << std::endl;
        std::cout << "Age: " << m1->getAge() << std::endl;
        std::cout << "Hunger: " << m1->getHunger() << std::endl;
        std::cout << "Stage: " << m1->getStage() << std::endl;
        std::cout << "Behaviour: " << m1->getBehaviour() << std::endl;
        std::cout << std::endl;
        m1->feed(10);

        if (m1->isDead()) {
            std::cout << "Mantis is dead" << std::endl;
            break;
        }
    }


    return 0;
}

