#ifndef _AudioBeep
#define _AudioBeep

#include <QtMultimedia/QAudioFormat>
#include <QtMultimedia/QAudioDeviceInfo>
#include <QtMultimedia/QAudioOutput>
#include <QDebug>
#include <QBuffer>

class AudioBeep : public QObject {

	Q_OBJECT

public:
	AudioBeep(QObject *w);

public slots:
	void play();

private:
	QObject* qparent;

	qreal sampleRate = 40000;   // sample rate
	qreal duration = 1.000;     // duration in seconds
	qreal frequency = 1000;     // frequency
	const quint32 n = static_cast<quint32>(duration * sampleRate);   // number of data samples

	QByteArray byteBuffer;
};

#endif
