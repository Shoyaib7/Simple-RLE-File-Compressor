# Simple-RLE-File-Compressor
A command-line utility written in C to compress and decompress files using a basic Run-Length Encoding (RLE) algorithm.

Features
Compresses files by encoding consecutive runs of identical bytes.

Decompresses files back to their original state.

Simple command-line interface.

Works on any file type by operating in binary mode.

How to Build
You will need a C compiler like GCC. To compile the program, run the following command in your terminal. This will create an executable file.

gcc mycompress.c -o mycompress

(On Windows, this command will produce mycompress.exe)

How to Use
The program is run from your terminal and takes three arguments: a mode (-c or -d), an input file path, and an output file path.

Running the Program
Modern terminals require you to specify that the program is in the current directory.

On Linux, macOS, or Git Bash on Windows: Prefix the program name with ./

On Windows (PowerShell or CMD): Prefix the program name with .\

Important Note: File Paths with Spaces
If your input or output file path contains spaces, you must wrap the entire path in double quotes (").

Example: .\mycompress.exe -c "C:\Users\Your Name\Documents\my file.txt" output.rle

Examples
Compression
Linux/macOS:

./mycompress -c original.txt compressed.rle

Windows:

.\mycompress.exe -c original.txt compressed.rle

Decompression
Linux/macOS:

./mycompress -d compressed.rle decompressed.txt

Windows (with a path containing spaces):

.\mycompress.exe -d "C:\Users\My User\Desktop\compressed.rle" decompressed.txt

