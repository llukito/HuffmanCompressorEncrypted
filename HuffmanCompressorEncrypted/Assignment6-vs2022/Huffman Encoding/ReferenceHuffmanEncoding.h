/*************************************************************************
 * File: ReferenceHuffmanEncoding.h
 */

#include "HuffmanEncoding.h"

/* Reference solution for getFrequencyTable. */
Map<ext_char, int> referenceGetFrequencyTable(istream & file);

/* Reference solution for buildEncodingTree. */
Node *referenceBuildEncodingTree(Map<ext_char, int> frequencies);