#include "audiobeep.h"

#define _USE_MATH_DEFINES
#include <math.h>

// constructor
AudioBeep::AudioBeep(QObject *w, float duration, float frequency, float volume) {
	qparent = w;
	
	audioFormat.setSampleRate(sampleRate);
	audioFormat.setChannelCount(1);
	audioFormat.setSampleSize(16);
	audioFormat.setCodec("audio/pcm");
	audioFormat.setByteOrder((QAudioFormat::Endian)QSysInfo::ByteOrder);
	audioFormat.setSampleType(QAudioFormat::SignedInt);
		
	QAudioDeviceInfo deviceInfo(QAudioDeviceInfo::defaultOutputDevice());
	if(!deviceInfo.isFormatSupported(audioFormat)) {
		throw "Raw audio format not supported by backend, cannot play audio.";
	}

	// number of data samples
	const unsigned int n = (unsigned int)round(duration * sampleRate);

	// resize byteBuffer to the total number of bytes that will be needed to accommodate
	// all the n data samples that are of type float
	byteBuffer.resize(sizeof(qint16) * n);

	// create the sinewave
	for (unsigned int i = 0; i < n; i++) {
		// create sine wave data samples, one at a time
		qint16 sinVal = (qint16)(sin(2.0 * M_PI * frequency * i / sampleRate)*32767*volume);
		( (qint16*)byteBuffer.constData() )[i] = sinVal;
	}	
	input  = new QBuffer(&byteBuffer, qparent);
	input->open(QIODevice::ReadOnly);
}

// play the audio
void AudioBeep::play() {
	input->seek(0);
	QAudioOutput* audio = new QAudioOutput(audioFormat, qparent);
	// Create a callback as a lambda expression which releases "input" and "audio"
	// after playing has finished, thus this allows async audio playing without blocking.
	connect(audio, &QAudioOutput::stateChanged, [this,audio](QAudio::State newState)
							    {
								    // finished playing (i.e., no more data)
								    if (newState == QAudio::IdleState)
								    {
									    audio->stop();
									    // delete the classes and release the memory
									    delete audio;
								    }
							    });
	// Start the audio (i.e., play sound from the QAudioOutput object) and return immediately to the caller.
	audio->start(input);
}
