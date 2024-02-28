#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "First test to setting up GitHub version control with Qt Creator" << std::endl;

    return a.exec();
}
