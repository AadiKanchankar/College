#include<bits/stdc++.h>
using namespace std;

class Song {
public:
    string title;
    string artist;
    string duration;
    Song *next;
    
    Song(string &title, string &artist, string &duration){
        this-> title = title;
        this-> artist = artist;
        this-> duration = duration;
        this-> next = NULL;
    }
};



class Playlist{
    Song* head;
public:
    
    Playlist() {
        head = NULL;
    }
    

    void AddSong(string title, string artist, string duration) {
        Song *newSong = new Song(title, artist, duration); // Defining a new node (nn)
        if (head == NULL){
            head = newSong;
            cout << endl << "The Playlist is empty. Hence the added Song becomes Start Song.";
            return;
        } 
        else {
            Song *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newSong;
        }
    }

    void RemoveSong(string title){
        if(head == NULL){
            cout << endl << "The Playlist is empty!";
            return;
        }

        if(head-> title == title){
            Song *temp = head;
            head = head-> next;
            delete temp;
        }

        Song* curr = head;
        Song *prev = NULL;

        while(curr-> title != title && curr->next != NULL){
            prev = curr;
            curr = curr-> next;
        }

        if(curr = NULL){
            cout << endl << "Song doesn't exist in the Playlist";
        }

        prev->next = curr->next;
        delete curr;
        cout << endl << "The song which was Removed:" << title;
    }

    void display() {
        if (head == NULL) {
            cout << endl << "The Playlist is empty." << endl;
            return;
        }
        cout << endl;
        Song *temp = head;

        while (temp != NULL) {
            cout << endl << "Song Title: " << temp-> title << " ";
            cout << endl << "Artist Name: " << temp-> artist << " ";
            cout << endl << "Duration: " << temp-> duration << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    void PlaySpecificSong(string title, string artist, string duration){
        Song *temp = head;
        while(temp != NULL){
            if(temp-> title == title){
                cout << endl << "Now Playing: " << title <<", By: " << artist << " of duration:" << duration;
                return;
            }
            temp-> next;
        }
        cout << "Song not Found" << title << endl;
    }
};

int main() {
    Playlist MusicPlayer;
    int choice;
    string title, artist, duration;

    do {
        cout << endl << "Menu:";
        //cout << endl << "1. Add music at the start";
        cout << endl << "1. Add a song ";
        cout << endl << "2. Delete a song ";
        cout << endl << "3. Display the entire Playlist ";
        cout << endl << "4. Play a specific Song ";
        cout << endl << "5. Exit";
        cout << endl <<"Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the song you want to add ";
            cout << endl << "Entire the song title: ";
            getline(cin,title);
            cin.ignore();
            //cin >> title;
            cout << endl << "Enter Artist name: ";
            getline(cin, artist);
            cin.ignore();
            cout << endl << "Enter duration of the song(Minutes:Seconds) : ";
            getline(cin, duration);
            cin.ignore();
            MusicPlayer.AddSong(title, artist, duration);
            break;
        case 2:
            cout << "Enter the Song Title which needs to be Removed: ";
            getline(cin, title);
            cin.ignore();
            MusicPlayer.RemoveSong(title);
            break;
        case 3:
            MusicPlayer.display();
            break;
        case 4:
            cout << endl << "Which Song would you like to play: ";
            getline(cin, title);
            cin.ignore();
            MusicPlayer.PlaySpecificSong(title, artist, duration);
            break;
        case 5:
            cout << "Exiting the Music Player! Thank You for visiting!";
            break;

        default:
            cout << endl << "Invalid choice! Please try again.";
        }
    } 
    
    while (choice != 5);

    return 0;
}
