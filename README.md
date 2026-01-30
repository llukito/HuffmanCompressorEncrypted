# HuffSecure: Encrypted File Compressor

![Language](https://img.shields.io/badge/language-C++-blue.svg)
![Standard](https://img.shields.io/badge/standard-C++17-green.svg)
![License](https://img.shields.io/badge/license-MIT-orange.svg)

HuffSecure is a high-performance command-line file compression tool built in C++. It implements the Huffman Coding algorithm for lossless data compression and adds a layer of security via XOR-based header obfuscation, ensuring that compressed archives remain inaccessible without the correct password.

## Key Features

- **Lossless Compression:** Reduces file size efficiently using frequency-based Huffman binary trees.
- **Secure Archives:** Protects the critical decoding header using XOR encryption logic. Without the password, the Huffman tree cannot be reconstructed, rendering the payload unreadable.
- **Memory Safe:** Implements strict memory management to ensure all encoding trees and buffers are deallocated post-process (0 bytes leaked).
- **Custom File Format:** Writes a serialized binary header containing the frequency table and encryption metadata.

## Technical Implementation

### The Compression Pipeline
1. **Frequency Analysis:** Scans the input file to build a frequency map of all bytes.
2. **Tree Construction:** Uses a Priority Queue to build a Huffman Tree, assigning shorter bit codes to more frequent characters.
3. **Header Encryption:** The serialized Huffman table is XORed against the user's password hash before being written to the file header.
4. **Bit Packing:** The payload is compressed bit-by-bit and packed into bytes for storage.

### Data Structures
- **Priority Queue:** Used for efficient tree building (O(N log N)).
- **Binary Trees:** Used for traversing the bitstream during decompression.

## Installation & Usage

### Prerequisites
- C++ Compiler (g++ or clang)
- Make (optional)

### Build
To compile the project manually:

    g++ -o huffsecure main.cpp huffman.cpp -O3

### Usage
Run the tool from the command line:

    ./huffsecure

Follow the interactive prompts:
1. **Compress:** Enter filename -> Enter Password -> Output generated (e.g., file.huf).
2. **Decompress:** Enter file.huf -> Enter Password -> Original file restored.

**Note on Security:** The current implementation uses XOR obfuscation, which is lightweight and efficient. It is intended to prevent casual access rather than defend against advanced cryptanalysis.

## Project Structure

    ├── src/
    │   ├── encoding.cpp       # Core Huffman algorithm implementation
    │   ├── bitstream.cpp      # Low-level bit packing/unpacking logic
    │   └── main.cpp           # CLI entry point
    ├── include/
    │   └── encoding.h         # Header definitions
    ├── README.md
    └── LICENSE

## Future Improvements
- Replace internal educational libraries with standard C++ STL (std::priority_queue).
- Implement AES-128 encryption for robust security.
- Add multi-threading support for compressing large files.

---

**Author:** Luka Aladashvili
