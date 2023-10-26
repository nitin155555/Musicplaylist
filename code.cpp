#include <iostream>
#include <string>

// Define the Song class to represent individual songs
class Song {
public:
    Song(const std::string& title, const std::string& artist) {
        this->title = title;
        this->artist = artist;
    }

    // Getter methods to access song information
    std::string getTitle() const {
        return title;
    }

    std::string getArtist() const {
        return artist;
    }

private:
    std::string title;
    std::string artist;
};

// Define the Node class to represent a node in the linked list
class Node {
public:
    Song song;
    Node* next;

    Node(const Song& song) {
        this->song = song;
        this->next = nullptr;
    }
};

// Define the Playlist class to manage the playlist
class Playlist {
public:
    Playlist() {
        head = nullptr;
        currentSong = nullptr;
    }

    // Add a song to the end of the playlist
    void addSong(const Song& song) {
        Node* newNode = new Node(song);
        if (head == nullptr) {
            head = newNode;
            currentSong = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Remove a song from the playlist
    void removeSong(const std::string& title) {
        if (head == nullptr) {
            std::cout << "Playlist is empty." << std::endl;
            return;
        }

        Node* prev = nullptr;
        Node* current = head;

        while (current != nullptr) {
            if (current->song.getTitle() == title) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
        std::cout << "Song not found in the playlist." << std::endl;
    }

    // Display the current playlist
    void displayPlaylist() {
        if (head == nullptr) {
            std::cout << "Playlist is empty." << std::endl;
        } else {
            Node* temp = head;
            while (temp != nullptr) {
                std::cout << temp->song.getTitle() << " by " << temp->song.getArtist() << std::endl;
                temp = temp->next;
            }
        }
    }

    // Move to the next song in the playlist
    void nextSong() {
        if (currentSong != nullptr && currentSong->next != nullptr) {
            currentSong = currentSong->next;
        } else {
            std::cout << "No next song available." << std::endl;
        }
    }

    // Move to the previous song in the playlist
    void previousSong() {
        if (currentSong == nullptr || currentSong == head) {
            std::cout << "No previous song available." << std::endl;
        } else {
            Node* temp = head;
            while (temp->next != currentSong) {
                temp = temp->next;
            }
            currentSong = temp;
        }
    }

private:
    Node* head;
    Node* currentSong;
};

int main() {
    Playlist myPlaylist;

    // Adding songs to the playlist
    myPlaylist.addSong(Song("Song 1", "Artist 1"));
    myPlaylist.addSong(Song("Song 2", "Artist 2"));
    myPlaylist.addSong(Song("Song 3", "Artist 3"));

    // Display the playlist
    myPlaylist.displayPlaylist();

    // Remove a song
    myPlaylist.removeSong("Song 2");

    // Display the updated playlist
    myPlaylist.displayPlaylist();

    // Move to the next song
    myPlaylist.nextSong();

    // Move to the previous song
    myPlaylist.previousSong();

    return 0;
}
