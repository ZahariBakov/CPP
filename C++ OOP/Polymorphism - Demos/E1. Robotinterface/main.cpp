#include "RealRobot.h"
#include "FakeRobot.h"

#include <memory>

int main() {
    bool shouldUseRealRobot = true; // Real robot
    //bool shouldUseRealRobot = false; // Fake robot

    std::unique_ptr<Robotnterface> robotPtr;

    if (shouldUseRealRobot) {
        robotPtr.reset(new RealRobot);
    }
    else {
        robotPtr.reset(new FakeRobot);
    }

    robotPtr->start();
    robotPtr->stop();
    robotPtr->doSomeWork();

    return 0;
}
