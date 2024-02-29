<div align="center">
  
  # Subnet Calculator
  
</div>

Welcome to my personal project repository, where I've developed a Subnet Calculator tool using C++. This project is a testament to my interest in network engineering and programming, combining both to create a utility that's both simple and powerful. The primary goal of this tool is to assist network administrators, students, and IT professionals in efficiently calculating various network parameters given an IP address and subnet mask. With this tool, users can quickly determine important network information such as the network address, broadcast address, the range of valid IP addresses within a subnet, and the total number of hosts it can support.

## Features

- **IP Address & Subnet Mask Input**: Users can input any valid IP address along with a subnet mask to perform calculations.
- **Network Information Calculation**: Computes the network address, broadcast address, and the range of valid IP addresses within the subnet.
- **Hosts Calculation**: Calculates the number of usable hosts per subnet.
- **CIDR Notation Support**: Accepts CIDR notation as input for subnet mask.
- **IPv4 Support**: Fully supports IPv4 addressing.

## Getting Started

To use the Subnet Calculator, you need to have a C++ compiler installed on your system. The program is console-based and can be compiled and run on various operating systems, including Windows, Linux, and macOS.

### Prerequisites

Ensure you have a C++ compiler installed:
- GCC for Linux
- MinGW for Windows
- Clang for macOS

### Installation

1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/cyberthirty/Subnet-Calculator.git
    ```
2. Navigate to the cloned repository:
    ```bash
    cd Subnet-Calculator
    ```
3. Compile the program using your C++ compiler. For example, using g++:
    ```bash
    g++ subnet_calculator.cpp -o subnet_calculator
    ```
4. Run the compiled program:
    ```bash
    ./subnet_calculator
    ```

## Usage

After starting the program, you will be prompted to enter an IP address and a subnet mask. You can enter the subnet mask in traditional dot-decimal notation or CIDR notation.

### Example

```
Enter IP address: 192.168.1.1
Enter Subnet Mask (e.g., 24 for /24): 30

Calculating...

Enter IP address: 192.168.1.1
Enter Subnet Mask (e.g., 24 for /24): 24
Network Address: 192.168.1.0
Broadcast Address: 192.168.1.255
First Usable IP Address: 192.168.1.1
Last Usable IP Address: 192.168.1.254
Number of Usable Hosts: 254
```

## Contributing

Contributions are welcome! If you'd like to contribute, please fork the repository and use a feature branch. Pull requests are warmly welcome.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
