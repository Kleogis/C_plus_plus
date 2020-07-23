#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
using namespace std;

class PlaylistNode {
  public:
    PlaylistNode();  //default constructor DONE 
    PlaylistNode(string , string , string , int ); // parameterized constructor DONE
    void InsertAfter(PlaylistNode* Next_N); //DONE
    void SetNext(PlaylistNode* Next_N); //DONE
    string GetID() const;               //DONE
    string GetSongName() const;         //DONE
    string GetArtistName()const;        //DONE
    int GetSongLength() const;          //DONE
    PlaylistNode* GetNext() const;      //DONE
    void PrintPlaylistNode();           //DONE
  private:
    string uniqueID;  //Initialized to "none" in default constructor
    string songName;  //Initialized to "none" in default constructor
    string artistName; //Initialized to "none" in default constructor
    int songLength;    //Initialized to 0 in default constructor
    PlaylistNode* nextNodePtr;  //Initialized to 0 in default constructor

};

#endif