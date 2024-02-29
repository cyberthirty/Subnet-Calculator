#include <iostream>
#include <bitset>
#include <string>

using namespace std;

// Function to calculate the number of hosts
int calculateHosts(int subnetMask) {
    return (1 << (32 - subnetMask)) - 2;
}

// Function to convert IP to binary
bitset<32> ipToBinary(string ip) {
    bitset<32> binaryIp;
    int octet;
    size_t pos = 0;
    int shift = 24; // Start with the first octet

    while ((pos = ip.find('.')) != string::npos) {
        octet = stoi(ip.substr(0, pos));
        binaryIp |= (octet << shift);
        shift -= 8;
        ip.erase(0, pos + 1);
    }
    octet = stoi(ip);
    binaryIp |= octet;

    return binaryIp;
}

// Function to convert binary IP to string
string binaryIpToString(bitset<32> binaryIp) {
    string ip = "";
    for (int i = 0; i < 32; i += 8) {
        ip += to_string((binaryIp >> (24 - i)).to_ulong() & 0xFF);
        if (i < 24) ip += ".";
    }
    return ip;
}

int main() {
    string ipAddress;
    int subnetMask;

    cout << "Enter IP address: ";
    cin >> ipAddress;
    cout << "Enter Subnet Mask (e.g., 24 for /24): ";
    cin >> subnetMask;

    bitset<32> binaryIp = ipToBinary(ipAddress);
    bitset<32> binaryMask = (0xFFFFFFFF << (32 - subnetMask)) & 0xFFFFFFFF;

    // Calculate network and broadcast addresses
    bitset<32> networkAddress = binaryIp & binaryMask;
    bitset<32> broadcastAddress = networkAddress | ~binaryMask;

    // Calculate first and last usable IP addresses
    bitset<32> firstUsableIp = networkAddress;
    firstUsableIp |= 1;
    bitset<32> lastUsableIp = broadcastAddress;
    lastUsableIp &= ~bitset<32>(1);

    cout << "Network Address: " << binaryIpToString(networkAddress) << endl;
    cout << "Broadcast Address: " << binaryIpToString(broadcastAddress) << endl;
    cout << "First Usable IP Address: " << binaryIpToString(firstUsableIp) << endl;
    cout << "Last Usable IP Address: " << binaryIpToString(lastUsableIp) << endl;
    cout << "Number of Usable Hosts: " << calculateHosts(subnetMask) << endl;

    return 0;
}
