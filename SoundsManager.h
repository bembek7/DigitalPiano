#ifndef SOUNDSMANAGER_H
#define SOUNDSMANAGER_H

#include <QSoundEffect>

enum Genre { House, Disco };
enum Sound { C, D, E, F, G, A, B };

class SoundsManager : public QObject
{
Q_OBJECT

public:
    SoundsManager(Genre genre = House);

    void ChangeVolume();

    void SetGenre(Genre newGenre);

    void LoadSounds();

    bool SoundsLoaded() const;

    void Play(Sound soundToPlay);

private:
    std::vector<std::unique_ptr<QSoundEffect>> sounds;
    Genre currentGenre;
    std::vector<std::string> genreNames = {"House", "Disco"};
    std::vector<std::string> soundNames = {"C", "D", "E", "F", "G", "A", "B"};
};


#endif // SOUNDSMANAGER_H
