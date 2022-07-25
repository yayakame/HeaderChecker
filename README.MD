# Header Checker

My most recent invention as of this date! Because I can't time travel!

Anyhow, jokes aside, this is my first C project
It is, indeed, a very simple and small one, and actually was based off of one of my C# ones

# Usage
Input a file path when the program asks for it. i.e.
 - C:\
 - .\Desktop

Refrain from using invalid paths, as it will just make the program exit (too lazy to implement that check tbh)
# How it works
It utilizes recursion as a mean to go through all sub-directories within a directory, also ignoring the (((comical))) '.' & '..' folders, since they are essentially invalid for the intent present here

When finding a file, it compares the pre-set header within the source code and the header from the file, appending it to a file if the comparison is successful

*max_depth* controls how deep the method can go before returning

*sub_f_path* is used to store the full path of the current file/folder

*path_output_file* is the name of the output file for outputting valid paths to (no need for full paths here)

The rest, go figure them out (L)