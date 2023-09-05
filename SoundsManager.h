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

    Qt::Key GetSoundBindedKey(Sound sound) const;

    bool SoundsLoaded() const;

    void Play(Sound soundToPlay);

private:
    std::vector<std::unique_ptr<QSoundEffect>> sounds;
    int currentPitch;
    std::vector<QString> soundNames = {"C", "D", "E", "F", "G", "A", "B", "CSharp", "DSharp", "FSharp", "GSharp", "ASharp"};
    std::vector<Qt::Key> soundBinds = {Qt::Key_Q, Qt::Key_W, Qt::Key_E, Qt::Key_O, Qt::Key_P, Qt::Key_BracketLeft, Qt::Key_BracketRight, Qt::Key_2, Qt::Key_3, Qt::Key_0, Qt::Key_Minus, Qt::Key_Equal};
};


#endif // SOUNDSMANAGER_H
