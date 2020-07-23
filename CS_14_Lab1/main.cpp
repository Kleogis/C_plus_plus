#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

void PrintMenu(string );

int main() {
  string PlayListName;
  cout << "Enter playlist's title:" << endl;
  getline(cin, PlayListName);
  cout << endl;
  PrintMenu(PlayListName);

return 0;
}

void PrintMenu(string PL_Name){
  PlaylistNode* head = NULL;
  PlaylistNode* tail = NULL;

  char Input;
  cout << PL_Name << " PLAYLIST MENU" << endl;
  cout << "a - Add song" << endl;
  cout << "d - Remove song" << endl;
  cout << "c - Change position of song" << endl;
  cout << "s - Output songs by specific artist" << endl;
  cout << "t - Output total time of playlist (in seconds)" << endl;
  cout << "o - Output full playlist" << endl;
  cout << "q - Quit" << endl;
  cout << endl;
  cout << "Choose an option:" << endl;
  cin >> Input;

  if (Input == 'q'){
    return;
  }
  while (Input != 'q'){

    if (Input == 'a'){
      //string ID, string S_Name, string A_Name, int S_Length
      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      string ID;
      cin >> ID;
      cin.ignore();
      cout << "Enter song's name:" << endl;
      string S_Name;
      getline(cin, S_Name);
      cout << "Enter artist's name:" << endl;
      string A_Name;
      getline(cin, A_Name);
      cout << "Enter song's length (in seconds):" << endl;
      int S_Length;
      cin >> S_Length;
      PlaylistNode* temp = new PlaylistNode(ID, S_Name, A_Name, S_Length);
        if(head == NULL) {
          head = temp;
          tail = temp;
        }
        else {
          tail->SetNext(temp);
          tail = temp;
        }
      cout << endl; 
    }
    else if (Input == 'd'){
      string ID_Rem = "";
      cout << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> ID_Rem;
      //if list is empty
      if (head == NULL){
        break;
      }
      else {
        for (PlaylistNode * i = head; i != NULL; i=i->GetNext()){
          string Temp_Song_Name; //Need to record for output before node removed
          Temp_Song_Name = i->GetSongName();
          //if song which need to be removed is in a Node#1...
          if (i->GetID() == ID_Rem) {
           
          //but it is not the only node in a PlayList
            if (i == head && i !=tail) {
              PlaylistNode* temp1 = head->GetNext();
              delete head;
              head = temp1;
              cout << "\"" << Temp_Song_Name << "\"" << " removed." << endl;
              break;
            }
          //and it is the only node in PlayList
            else if (i == head && i == tail){
              delete head;
              head = NULL;
              tail = NULL;
              cout << "\"" << Temp_Song_Name << "\"" << " removed." << endl;
              break;
            }        
          }
          PlaylistNode *temp = NULL;
          PlaylistNode *previous = NULL;
          previous = i;
          for (temp = i->GetNext(); temp != 0; temp= temp->GetNext()){
            if (temp->GetID() == ID_Rem){
              Temp_Song_Name = temp->GetSongName();
              if (temp == tail){
                tail = previous;
                delete temp;
              }
   
              previous->SetNext(temp->GetNext());
              delete temp;
              cout << "\"" << Temp_Song_Name << "\"" << " removed." << endl;
            }
            else{
            previous = previous->GetNext(); 
            } 
          } 
        }
      }       
      cout << endl;
    }
    else if (Input == 'c'){
      cout << "CHANGE POSITION OF SONG" << endl;
      cout << "Enter song's current position:" << endl;
      PlaylistNode* temp2 = NULL;
      int count = 0;
      int Song_Cur_Pos = 0;
      cin >> Song_Cur_Pos; 
      cout << "Enter new position for song:" << endl;
      int Song_New_Pos = 0;
      cin >> Song_New_Pos;
      if(head == NULL){
        break;
      }
      else{
        //total amount of song positions in the list in order to get the position of last song
        int Last_Song;
        for (PlaylistNode* i = head; i != NULL; i = i->GetNext()) {
          ++Last_Song;
        }
        //if user want to move the first node assign temp pointer to the first node
        if (Song_Cur_Pos == 1) {
          temp2 = head;
          head = head->GetNext();
        }
        //if user want to move the last node assign temp pointer to the last node;
        else if (Song_Cur_Pos == Last_Song) {
          temp2 = tail;
          //moving tail node;
          for (PlaylistNode* i = head; i->GetNext()->GetNext() != NULL; i = i->GetNext()) {
            tail = i;
          }
          tail = tail->GetNext();
          tail->SetNext(NULL);
        }
        else {
          count = 1;
          for (PlaylistNode* i = head; i != NULL; i = i->GetNext()) {
           if (count == Song_Cur_Pos - 1) {
              temp2 = i->GetNext();
              i->SetNext(i->GetNext()->GetNext());
            }
            ++count;
          }
        }
        count = 1;
        if(Song_New_Pos == 1) {
         PlaylistNode* temp = head;
          head = temp2;
          temp2->SetNext(temp);
        }
          else {
            for(PlaylistNode* i = head; i != NULL; i = i->GetNext()) {
              if(count == Song_New_Pos - 1) {
               PlaylistNode* temp = i->GetNext();
                i->SetNext(temp2);
                temp2->SetNext(temp);
              }
              ++count;
            }
          }
          cout << "\"" << temp2->GetSongName() << "\"" << " moved to position " << Song_New_Pos << endl << endl;
        }
      }
      else if (Input == 's'){
        string Artist;
        cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
        cout << "Enter artist's name:" << endl;
        cin.ignore();
        getline(cin, Artist);
        cout << endl;
        int count = 1;
          for(PlaylistNode* i = head; i != NULL; i = i->GetNext()) {
            if(i->GetArtistName() == Artist) {
              cout << count << "." << endl;
              i->PrintPlaylistNode();
              cout << endl << endl;
            }
            ++count;
      }
    }
    else if (Input == 't'){
      int Length = 0;
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      if(head != NULL){
        for(PlaylistNode* i = head; i != NULL; i = i->GetNext()) {
          Length = Length + i->GetSongLength();
        }
        cout << "Total time: " << Length << " seconds" << endl;
        cout << endl;
      }
      else{
        cout << "Total time: 0 seconds" << endl;
        cout << endl;
      }
    }
    else if (Input == 'o'){
      if (head == NULL){
        cout << PL_Name << " - OUTPUT FULL PLAYLIST" << endl;
        cout << "Playlist is empty" << endl;
        cout << endl;
      }
      else{
        cout << PL_Name << " - OUTPUT FULL PLAYLIST" << endl;
        int count = 1;
        for (PlaylistNode * i = head; i != NULL; i=i->GetNext()){
          cout << count << "." << endl;
          i->PrintPlaylistNode();
          cout << endl;
          cout << endl;
          count++;
        }
        //cout << endl;
      }
    }
    else{
      cout << "Enter valid input" << endl;
    }
    cout << PL_Name << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;
    cin >> Input;
  }
}