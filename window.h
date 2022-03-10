#include "audiobeep.h"
#include <QVBoxLayout>
#include <QPushButton>

class Window : public QWidget
{
	Q_OBJECT

public:
	Window();

	void playBeep() {
		audiobeep->play();
	}

private:
	QPushButton* button;
	AudioBeep* audiobeep;
};
