#include "all_headers.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    w.showFullScreen();

    //manage_window w;
    //w.show();

    return a.exec();


    //return 0;
}
