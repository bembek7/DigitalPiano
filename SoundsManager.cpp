#include "SoundsManager.h"

SoundsManager::SoundsManager(Genre genre)
{
    LoadSounds(genre);
    auto effect = std::make_unique<QSoundEffect>();
    effect->setSource(QUrl("qrc:Sounds/CSound.wav"));
    sounds.push_back(std::move(effect));
}

void SoundsManager::ChangeVolume()
{
    ;
}

void SoundsManager::LoadSounds(Genre genre)
{
    currentGenre = genre;
}

bool SoundsManager::SoundsLoaded() const
{
    return true;
}

void SoundsManager::Play(Sound sound)
{
    sounds[sound]->play();
}
