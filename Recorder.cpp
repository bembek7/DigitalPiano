#include "Recorder.h"
#include <QUrl>
#include <QDir>

Recorder::Recorder(QObject *parent)
    : QObject{parent}
{
    session.setAudioInput(&audioInput);
    session.setRecorder(&recorder);
    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/amr");
    audioSettings.setQuality(QMultimedia::HighQuality);
    recorder.setEncodingMode(Settings(QAudioEncoderSettings(), QVideoEncoderSettings(), "audio/x-wav");
    recorder.setOutputLocation(QUrl::fromLocalFile("test.wav"));
}

void Recorder::StartRecording()
{
    qDebug() << recorder.outputLocation();
    recorder.record();
}

void Recorder::PauseRecording()
{
    recorder.pause();
}

void Recorder::StopRecording()
{
    recorder.stop();
}
