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
  Album album = {"unknown", song};
  Artiste artiste = {"inconnu", album};
  addSong("song","","singer", discography);
  assert(isItHere(discography, artiste)=!-1);
};

/**
 *This function verify that if the song is not given it will be replace by "unknown"
 *the results would be "Unknown | Album | Singer"
 */
void addSongAddUnknownIfSongNotGiven(){
  Song song = {"unknown"};
  Album album = {"album", song};
  Artiste artiste = {"singer", album};
  addSong("","album","singer", discography);
  assert(isItHere(discography, artiste)=!-1);
};

/**
 *This function verify that if the singer is not given it will be replace by "unknown"
 *the results would be "Song | Album | Unknown"
 */
void addSongAddUnknownIfSingerNotGiven(){
  Song song = {"song"};
  Album album = {"album", song};
  Artiste artiste = {"unknown", album};
  addSong("song","album","", discography);
  assert(isItHere(discography, artiste)=!-1);
};

/**this function will verify that if th euser want to add a song that is already in the discography,
 *it will not be added again
 */
void addSong_addNothingIfSongExistAlready(){
  int cpt =0;
  Song song = {"Blinding Lights"};
  Album album = {"After Hours", {song}};
  Artiste artiste = {"The Weeknd", {album}};
  addSong(song,album.name,artiste.name, discography);
  addSong(song,album.name,artiste.name, discography);

  for(auto i = discography.begin();i!=discography.end();i++){
    if(i->first==artiste.name){
      for(int j = 0; j<i->second.album.size();j++){
	if(i->second.album[j].name==album.name){
	  for(int k =0; k<i->second.album[j].song.size();k++){
	    if(i->second.album[j].song[k].name==song.name){
	      cpt++;
       }}}}}}
  assert(cpt==1);
};

void addSong_addNewSongToAnExistentAlbum(){};

void addSong_addNewAlbumToAnExistentSinger(){};

int main(){
  return 0;

}

