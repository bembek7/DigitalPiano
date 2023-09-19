#include "SoundsManager.h"
#include <QUrl>
#include <QString>

SoundsManager::SoundsManager(int pitch)
{
    int nrOfSounds = 12;
    sounds.reserve(nrOfSounds);
    std::generate_n(std::back_inserter(sounds), nrOfSounds, [] { return std::make_unique<QSoundEffect>(); });
    currentPitch = pitch;
    LoadSounds();
}

void SoundsManager::SetPitch(int newPitch)
{
    if(currentPitch != newPitch)
    {
        currentPitch = newPitch;
        LoadSounds();
    }
}

Qt::Key SoundsManager::GetSoundBindedKey(Sound sound) const
{
    return soundBinds[sound];
}

void SoundsManager::ChangeVolume(float newVolume)
{
    newVolume /= 100;
    for(auto& sound : sounds)
    {
        sound->setVolume(newVolume);
    }
}

void SoundsManager::LoadSounds()
{
    int i = 0;
    for(auto& sound : sounds)
    {
        QString path = QString("qrc:Sounds/");
        path.append(QString::number(currentPitch));
        path.append("/");
        path.append(soundNames[i]);
        path.append(".wav");
        sound->setSource(QUrl(path));
        i++;
    }
    //throw exception file
}

bool SoundsManager::SoundsLoaded() const
{
    return true;
}

void SoundsManager::ChangeBinding(Sound sound, const Qt::Key& newKey)
{
    soundBinds[sound] = newKey;
}

void SoundsManager::Play(Sound sound)
{
    sounds[sound]->play();
}
