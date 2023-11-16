#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SongManager {
private:
    vector<vector<string>> songList;

public:
    SongManager() {}

    void AddSong() {
        vector<string> song(4);

        cout << "Enter song title: ";
        cin.ignore();
        getline(cin, song[0]);

        cout << "Enter artist: ";
        getline(cin, song[1]);

        cout << "Enter album: ";
        getline(cin, song[2]);

        cout << "Enter duration (in seconds): ";
        cin >> song[3];

        songList.push_back(song);
        cout << "Song added successfully.\n";
    }

    void DisplaySong(const vector<string>& song, int position) const {
        cout << "Song " << position + 1 << ": " << song[0] << " by " << song[1] << "\n";
    }

    void AccessSong(int position) const {
        if (position < 0 || position >= songList.size()) {
            cout << "Invalid song position.\n";
            return;
        }
        DisplaySong(songList[position], position);
    }

    void UpdateSong(int position) {
        if (position < 0 || position >= songList.size()) {
            cout << "Invalid song position.\n";
            return;
        }

        cout << "Re-Enter details for the Song:\n";
        AddSong();
        songList[position] = songList.back();
        songList.pop_back();

        cout << "Song updated successfully.\n";
    }

    void DeleteSong(int position) {
        if (position < 0 || position >= songList.size()) {
            cout << "Invalid song position.\n";
            return;
        }

        songList.erase(songList.begin() + position);
        cout << "Song deleted successfully.\n";
    }

    int GetSize() const {
        return songList.size();
    }

    bool IsEmpty() const {
        return songList.empty();
    }

    void ReorderSongs(int fromPosition, int toPosition) {
        if (fromPosition < 0 || fromPosition >= songList.size() ||
            toPosition < 0 || toPosition >= songList.size()) {
            cout << "Invalid song positions for reordering.\n";
            return;
        }

        swap(songList[fromPosition], songList[toPosition]);
        cout << "Songs reordered successfully.\n";
    }

    void SortSongs(int attributeIndex) {
        if (attributeIndex < 1 || attributeIndex > 4) {
            cout << "Invalid sorting attribute index.\n";
            return;
        }

        sort(songList.begin(), songList.end(),
             [attributeIndex](const vector<string>& a, const vector<string>& b) {
                 return a[attributeIndex] < b[attributeIndex];
             });

        cout << "Songs sorted by attribute " << attributeIndex << " successfully.\n";
    }
};

int main() {
    SongManager songManager;
    
    cout << "\nWelcome To My Chinese Copy Of Spotify\n";
    
    int choice;
    do {
        cout << "1. To Add Song\n";
        cout << "2. To Access Song\n";
        cout << "3. To Update Song\n";
        cout << "4. To Delete Song\n";
        cout << "5. To Reorder Songs\n";
        cout << "6. To Sort Songs\n";
        cout << "7. To Display Songs\n";
        cout << "8. To Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                songManager.AddSong();
                break;
            case 2: {
                int position;
                cout << "Enter song position: ";
                cin >> position;
                songManager.AccessSong(position);
                break;
            }
            case 3: {
                int position;
                cout << "Enter song position: ";
                cin >> position;
                songManager.UpdateSong(position);
                break;
            }
            case 4: {
                int position;
                cout << "Enter song position: ";
                cin >> position;
                songManager.DeleteSong(position);
                break;
            }
            case 5: {
                int fromPosition, toPosition;
                cout << "Enter source position: ";
                cin >> fromPosition;
                cout << "Enter destination position: ";
                cin >> toPosition;
                songManager.ReorderSongs(fromPosition, toPosition);
                break;
            }
            case 6: {
                int attributeIndex;
                cout << "Enter sorting attribute index (1 for Title, 2 for Artist, 3 for Album, 4 for Duration): ";
                cin >> attributeIndex;
                songManager.SortSongs(attributeIndex);
                break;
            }
            case 7: {
                cout << "\nSongs:\n";
                for (int i = 0; i < songManager.GetSize(); ++i) {
                    songManager.AccessSong(i);
                }
                break;
            }
            case 8:
                cout << "Thanks for using My Spoooootiiiffffyyyyyy!!!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
