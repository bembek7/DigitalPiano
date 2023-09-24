#ifndef RECORDER_H
#define RECORDER_H

#include <QObject>
#include <QMediaCaptureSession>
#include <QAudioInput>
#include <QAudioRecorder>

class Recorder : public QObject
{
    Q_OBJECT
public:
    explicit Recorder(QObject *parent = nullptr);
    void StartRecording();
    void PauseRecording();
    void StopRecording();

private:
    QMediaCaptureSession session;
    QAudioInput audioInput;
    QAudioRecorder recorder;
};

#endif // RECORDER_H
