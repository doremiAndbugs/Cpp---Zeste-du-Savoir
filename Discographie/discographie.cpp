
#include <iostream>
#include <string>
#include <vector>

struct Song{
  std::string name;
};

struct Album{
  std::string name;
  std::vector<Song> song;
};

struct Artiste{
  std::string name;
  std::vector<Album> album:
};

void addSong(std::optional<string> & song ,std::optional<string> & album,std::optional<string> & singer, Discography){
  
  if(!song){
    addSong("inconnu", album, singer);
  }
  
  if(!album){
    addSong(song, "inconnu", singer);
  }

  if(!singer){
    addSong(song, album, "inconnu");
  }

  Song song_s;
  Album album_s;
  Artiste artiste_s;
  if(!discography[artiste]){
    song_s.name = song ;
    album_s.name = album;
    album_s.song= {song_s};
    artiste_s.name = singer;
    artiste_s.album = {album_s};
    Discography[singer] = artiste_s;
    return;
  }
  int pos_album = isItHere(discography[artiste].album, album);
  if(pos_album==-1){
    song_s.name = song ;
    album_s.name = album;
    album_s.song= {song_s};
    Discography[singer].album.push_back(Album);
    pos_album =  Discography[singer].album.size()-1;
    return
  }

  int pos_song = isItHere(discography[artiste].album[pos_album].song, song);
  if(pos_song==-1){
    song_s.name = song ;
    Discography[singer].album[pos_album].push_back(Song);
    return;
  }

  std::cout << "the song" << song <<" | " << album <<" | " << singer << " is already in your discography."<< std::endl;

  return;

}

using Discography = std::map<string,Artiste>;

int main(){
  return 0;
}
