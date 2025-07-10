/*******************************************************
 * File: HuffmanEncoding.h
 *
 * Definitions for the functions necessary to build a
 * Huffman encoding system.
 */

#ifndef HuffmanEncoding_Included
#define HuffmanEncoding_Included

#include "HuffmanTypes.h"
#include "map.h"
#include "bstream.h"

/* Function: getFrequencyTable
 * Usage: Map<ext_char, int> freq = getFrequencyTable(file);
 * --------------------------------------------------------
 * Given an input stream containing text, calculates the
 * frequencies of each character within that text and stores
 * the result as a Map from ext_chars to the number of times
 * that the character appears.
 *
 * This function will also set the frequency of the PSEUDO_EOF
 * character to be 1, which ensures that any future encoding
 * tree built from these frequencies will have an encoding for
 * the PSEUDO_EOF character.
 */
Map<ext_char, int> getFrequencyTable(istream& file);

/* Function: buildEncodingTree
 * Usage: Node* tree = buildEncodingTree(frequency);
 * --------------------------------------------------------
 * Given a map from extended characters to frequencies,
 * constructs a Huffman encoding tree from those frequencies
 * and returns a pointer to the root.
 *
 * This function can assume that there is always at least one
 * entry in the map, since the PSEUDO_EOF character will always
 * be present.
 */
Node* buildEncodingTree(Map<ext_char, int>& frequencies);

/* Function: freeTree
 * Usage: freeTree(encodingTree);
 * --------------------------------------------------------
 * Deallocates all memory allocated for a given encoding
 * tree.
 */
void freeTree(Node* root);

/* Function: encodeFile
 * Usage: encodeFile(source, encodingTree, output);
 * --------------------------------------------------------
 * Encodes the given file using the encoding specified by the
 * given encoding tree, then writes the result one bit at a
 * time to the specified output file.
 *
 * This function can assume the following:
 *
 *   - The encoding tree was constructed from the given file,
 *     so every character appears somewhere in the encoding
 *     tree.
 *
 *   - The output file already has the encoding table written
 *     to it, and the file cursor is at the end of the file.
 *     This means that you should just start writing the bits
 *     without seeking the file anywhere.
 */
void encodeFile(istream& infile, Node* encodingTree, obstream& outfile);

/* Function: decodeFile
 * Usage: decodeFile(encodedFile, encodingTree, resultFile);
 * --------------------------------------------------------
 * Decodes a file that has previously been encoded using the
 * encodeFile function.  You can assume the following:
 *
 *   - The encoding table has already been read from the input
 *     file, and the encoding tree parameter was constructed from
 *     this encoding table.
 *
 *   - The output file is open and ready for writing.
 */
void decodeFile(ibstream& infile, Node* encodingTree, ostream& file);

/* Function: writeEncryptedFileHeader
 * Usage: writeEncryptedFileHeader(output, frequencies, password);
 * ----------------------------------------------------------------
 * Writes an encrypted header to the beginning of the output file
 * containing the frequency table of all characters in the input.
 *
 * The table is encrypted using a simple XOR-based scheme with a
 * password provided by the user. This ensures that the compressed
 * file cannot be properly decompressed without the same password.
 *
 * Note: You must use readEncryptedFileHeader to correctly decrypt
 * and reconstruct the frequency table during decompression.
 */

void writeEncryptedFileHeader(obstream& outfile, Map<ext_char, int>& frequencies, const string& password);

/* Function: readEncryptedFileHeader
 * Usage: Map<ext_char, int> freq = readEncryptedFileHeader(input, password);
 * ---------------------------------------------------------------------------
 * Reads and decrypts the encrypted frequency table at the beginning of the
 * compressed file using the provided password. This table contains the
 * frequencies of all characters used in the original file, and is essential
 * for reconstructing the Huffman encoding tree during decompression.
 *
 * The decryption is performed using the same XOR-based scheme as the
 * writeEncryptedFileHeader function. If the password is incorrect,
 * the decoded data will be invalid and decompression will fail.
 *
 * Note: This function must match the format used by writeEncryptedFileHeader
 * to correctly interpret the file header.
 */
Map<ext_char, int> readEncryptedFileHeader(ibstream& infile, const string& password);

/* Function: compress
 * Usage: compress(infile, outfile);
 * --------------------------------------------------------
 * Main entry point for the Huffman compressor.  Compresses
 * the file whose contents are specified by the input
 * ibstream, then writes the result to outfile.  Your final
 * task in this assignment will be to combine all of the
 * previous functions together to implement this function,
 * which should not require much logic of its own and should
 * primarily be glue code.
 */
void compress(ibstream& infile, obstream& outfile);

/* Function: decompress
 * Usage: decompress(infile, outfile);
 * --------------------------------------------------------
 * Main entry point for the Huffman decompressor.
 * Decompresses the file whose contents are specified by the
 * input ibstream, then writes the decompressed version of
 * the file to the stream specified by outfile.  Your final
 * task in this assignment will be to combine all of the
 * previous functions together to implement this function,
 * which should not require much logic of its own and should
 * primarily be glue code.
 */
void decompress(ibstream& infile, ostream& outfile);

#endif
