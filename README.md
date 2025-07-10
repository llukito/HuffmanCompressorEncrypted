# HuffmanCompressorEncrypted
A file compression and decompression program using Huffman Encoding with password-protected headers.

# Huffman Encoding with XOR Password Encryption

This project is an extension of the Stanford Programming Abstractions challenge on Huffman encoding.  
I took the original challenge to the next level by adding XOR-based password encryption for the encoding header,  
making the compressed files secure and accessible only with the correct password.

## Features
- Huffman compression and decompression  
- Password-protected encoding header using XOR encryption  
- User-friendly command-line interface for compression and decompression  
- Memory management with clean-up of encoding trees  

## Usage
Run the program, and you will be prompted to enter a password for encryption/decryption.  
Make sure to use the same password for compressing and decompressing files.

## Technologies
- C++  
- Stanford C++ Libraries (pqueue, simpio, ibstream/obstream)
---

Feel free to explore, test, and provide feedback!

