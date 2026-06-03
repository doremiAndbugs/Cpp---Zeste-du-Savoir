#include "discography.h"
#include <cassert>

/**
 *This functions verify that if there is no given parameters,
 *it will replace everything by "unknown" and will add "Unknwon | Unknown |Unknown"
 */
void addSongAddUnknownIf0Parameters(){
  Song song = {"inconnu"};
  Album album = {"inconnu", song};
  Artiste artiste = {"inconnu", album};
  addSong(discography);
  assert(isItHere(discography, artiste)=!-1);
};

void addSongAddUnknownIfAlbumNotGiven(){};

void addSongAddUnknownIfSongNotGiven(){};

void addSongAddUnknownIfSingerNotGiven(){};

void addSong_addNothingIfSongExistAlready(){};

void addSong_addNewSongToAnExistentAlbum(){};

void addSong_addNewAlbumToAnExistentSinger(){};

int maint(){
  return 0;

}

