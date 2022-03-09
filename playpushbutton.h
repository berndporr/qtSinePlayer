#ifndef _QPLAYBUTTON
#define _QPLAYBUTTON

#include<QPushButton>
#include "audiobeep.h"

// let's create a window which just contains a button and it hosts the player
class QPlayButton : public QPushButton {
	Q_OBJECT
public:
	QPlayButton() : QPushButton() {
		connect(this, &QPushButton::clicked,
			this, &QPlayButton::buttonPressed );
		audiobeep = new AudioBeep(this);
	}

	~QPlayButton() {
		delete audiobeep;
	};

	void buttonPressed() {
		audiobeep->play();
	}

private:
	AudioBeep* audiobeep;
};

#endif
