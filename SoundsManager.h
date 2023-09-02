#ifndef SOUNDSMANAGER_H
#define SOUNDSMANAGER_H

#include <QSoundEffect>

enum Sound { C, D, E, F, G, A, B, CSharp, DSharp, FSharp, GSharp, ASharp };

class SoundsManager : public QObject
{
Q_OBJECT

public:
    SoundsManager(int pitch = 4);

    void ChangeVolume(float newVolume);

    void SetPitch(int newPitch);

    void LoadSounds();

    void SetSoundReady(bool isReady, Sound sound);

    bool SoundsLoaded() const;

    void Play(Sound soundToPlay);

private:
    std::vector<std::unique_ptr<QSoundEffect>> sounds;
    int currentPitch;
    std::vector<QString> soundNames = {"C", "D", "E", "F", "G", "A", "B", "CSharp", "DSharp", "FSharp", "GSharp", "ASharp"};
};


#endif // SOUNDSMANAGER_H
