#ifndef SOUNDSMANAGER_H
#define SOUNDSMANAGER_H

#include <QSoundEffect>

enum Genre { house, disco };
enum Sound { c, d, e, g, a, b};

class SoundsManager : public QObject
{
Q_OBJECT

public:
    SoundsManager(Genre genre = house);

    void ChangeVolume();

    void LoadSounds(Genre genre);

    bool SoundsLoaded() const;

    void Play(Sound soundToPlay);

private:
    std::vector<std::unique_ptr<QSoundEffect>> sounds;
    Genre currentGenre;
};


#endif // SOUNDSMANAGER_H
