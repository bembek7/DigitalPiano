#include "SoundsManager.h"
#include <QUrl>
#include <QString>

SoundsManager::SoundsManager(Genre genre)
{
    int nrOfSounds = 12;
    sounds.reserve(nrOfSounds);
    std::generate_n(std::back_inserter(sounds), nrOfSounds, [] { return std::make_unique<QSoundEffect>(); });
    currentGenre = genre;
    LoadSounds();
}

void SoundsManager::SetGenre(Genre newGenre)
{
    if(currentGenre != newGenre)
    {
        currentGenre = newGenre;
        LoadSounds();
    }
}

void SoundsManager::SetSoundReady(bool isReady, Sound sound)
{
    soundsReady[sound] = isReady;
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
        path.append(genreNames[currentGenre]);
        path.append("/");
        path.append(soundNames[i]);
        path.append("Sound.wav");
        sound->setSource(QUrl(path));
        i++;
    }
}

bool SoundsManager::SoundsLoaded() const
{
    return true;
}

void SoundsManager::Play(Sound sound)
{
    if(soundsReady[sound])sounds[sound]->play();
}
