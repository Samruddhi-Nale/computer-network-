/*receiver(seqNo, frameData): Processes the received frame and simulates sending back an 
(ACK) with 
the next expected sequence number (1 - seqNo).

sender(totalFrames): Transmits each frame one by one, waits for the corresponding ACK 
before advancing, 
and handles timeouts/retransmissions if an ACK is lost.

Sequence Alternation: Toggles between 0 and 1 to prevent duplicate processing at the 
receiver.*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
// Function to simulate the receiver
// Returns true if ACK is successfully received, false if ACK is lost/corrupted
bool receiver(int seqNo, int frameData){
    cout << "[Receiver] Frame " << frameData << " with Seq No " << seqNo << " received.\n";
    
    // Simulate ACK transmission (e.g., 85% success rate)
    bool ackSuccess = (rand() % 100) < 85; 
    
    if (ackSuccess){
        int expectedAck = 1 - seqNo; // Next expected sequence number
       cout << "[Receiver] Sending ACK for next expected Seq No: " << expectedAck << "\n";
        return true;
    } else{
        cout << "[Receiver] ACK lost in transmission!\n";
        return false;
    }
}

// Function to simulate the sender
void sender(int totalFrames){
    int seqNo = 0; // Sequence number alternates between 0 and 1

    for (int frame = 1; frame <= totalFrames; ++frame){
        bool ackReceived = false;

        while (!ackReceived){
            cout << "\n[Sender] Sending Frame " << frame << " (Seq No: " << seqNo << ")...\n";
            
            // Send frame to receiver and wait for ACK
            ackReceived = receiver(seqNo, frame);

            if (ackReceived){
                std::cout << "[Sender] ACK received successfully. Transmission verified.\n";
                seqNo = 1 - seqNo; // Alternate sequence number (0 -> 1 -> 0)
            } else{
                cout << "[Sender] Timeout! No ACK received. Resending Frame " << frame << "...\n";
            }
        }
    }
    cout << "\n============================================\n";
    cout << "All " << totalFrames << " frames transmitted successfully.\n";
    cout << "============================================\n";
}

int main(){
    srand(static_cast<unsigned int>(time(nullptr)));

    int totalFrames = 0;
    cout << "Enter how many sequence of frames you want to implement: ";
    cin >> totalFrames;

    if (totalFrames <= 0){
        cout << "Invalid number of frames. Exiting.\n";
        return 0;
    }

    // Start transmission
    sender(totalFrames);
    return 0;
}