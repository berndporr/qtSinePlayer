#include "audiobeep.h"
#include "playpushbutton.h"
#include<QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QPlayButton button;
    button.resize(100, 50);
    button.setText("Play");
    button.show();
    return app.exec();
}
