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

/**
 *This function verify that if the album is not given it will be replace by "unknown"
 *the results would be "song | Unknown | Singer"
 */
void addSongAddUnknownIfAlbumNotGiven(){
  Song song = {"song"};
  Album album = {"", song};
  Artiste artiste = {"inconnu", album};
  addSong("song","","singer", discography);
  assert(isItHere(discography, artiste)=!-1);
};

/**
 *This function verify that if the song is not given it will be replace by "unknown"
 *the results would be "Unknown | Album | Singer"
 */
void addSongAddUnknownIfSongNotGiven(){
  Song song = {""};
  Album album = {"album", song};
  Artiste artiste = {"singer", album};
  addSong("","album","singer", discography);
  assert(isItHere(discography, artiste)=!-1);
};

void addSongAddUnknownIfSingerNotGiven(){};

void addSong_addNothingIfSongExistAlready(){};

void addSong_addNewSongToAnExistentAlbum(){};

void addSong_addNewAlbumToAnExistentSinger(){};

int main(){
  return 0;

}

