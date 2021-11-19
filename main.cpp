#include <QtWidgets>
#include <QtMultimedia/QAudioFormat>
#include <QtMultimedia/QAudioDeviceInfo>
#include <QtMultimedia/QAudioOutput>

#include "audiobeep.h"
#include "playpushbutton.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QPlayButton button;
    button.resize(100, 50);
    button.setText("Play");
    button.show();
    return app.exec();
}
