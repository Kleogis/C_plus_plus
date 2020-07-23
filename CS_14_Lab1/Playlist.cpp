#include <iostream>
#include <vector>
#include "Playlist.h"
using namespace std;


PlaylistNode::PlaylistNode(){
  uniqueID = "none";  //Initialized to "none" in default constructor
  songName = "none";  //Initialized to "none" in default constructor
  artistName = "none"; //Initialized to "none" in default constructor
  songLength = 0;    //Initialized to 0 in default constructor
  nextNodePtr = NULL;
}

PlaylistNode::PlaylistNode(string ID, string S_Name, string A_Name, int S_Length){
  uniqueID = ID;
  songName = S_Name;
  artistName = A_Name;
  songLength = S_Length;    
  nextNodePtr = NULL;
}

void PlaylistNode::InsertAfter(PlaylistNode* Next_N){
  //EXAMPLE FROM ZYBOOK CHAPTER 1.8
//   void IntNode::InsertAfter(IntNode* nodeLoc) {
//    IntNode* tmpNext = nullptr;
   
//    tmpNext = this->nextNodePtr;    // Remember next
//    this->nextNodePtr = nodeLoc;    // this -- node -- ?
//    nodeLoc->nextNodePtr = tmpNext; // this -- node -- next
// }
  PlaylistNode* temp = NULL;
  temp = nextNodePtr;
  nextNodePtr = Next_N;
  Next_N->SetNext(temp);
}

void PlaylistNode::SetNext(PlaylistNode* Next_N){
  nextNodePtr = Next_N;
}

string PlaylistNode::GetID() const{
  return this->uniqueID;
}

string PlaylistNode::GetSongName() const{
  return this->songName;
}

string PlaylistNode::GetArtistName()const{
  return this->artistName;
}

int PlaylistNode::GetSongLength() const{
  return this->songLength;
}

PlaylistNode* PlaylistNode::GetNext() const{
  return this->nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode(){
//Print Function Output
// Unique ID: S123
// Song Name: Peg
// Artist Name: Steely Dan
// Song Length (in seconds): 237
  cout << "Unique ID: " << GetID() << endl;
  cout << "Song Name: " << GetSongName() << endl;
  cout << "Artist Name: " << GetArtistName() << endl;
  cout << "Song Length (in seconds): " << GetSongLength();
}
