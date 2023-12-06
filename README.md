# File_CompressorTool
The text file compression tool utilizes the Huffman encoding algorithm, providing the advantage of lossless compression. With this algorithm, data compression of up to 30-40% is achievable without compromising data integrity, resulting in a space savings of 60-70%.
# Working
### Compression
1. Find frequencies of characters and generate a Huffman Tree
2. Traverse, and assign bitcodes to each character, and store in map
3. Using this info, create a bitstring of the input file
4. Read this bitstring in chunks of 8
5. Write these bytes to file
### Decompression
1. Generate bitstring of compressed file
2. Go through each bit, comparing with the huffman codes, and appending characters to a vector on match
3. Write this vector to the file, which would be our uncompressed version
