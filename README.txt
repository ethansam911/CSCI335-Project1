
To compile on terminal g++ type: 
  make clean 
  make all

To delete executables and object file type
  make clean

To run:

./test_points2 

^^Doing this assumes you will give the points from user input:
//The first integer determines the number of points, every proceeding integer are the actual points
Example string: (3 4 5 5 3 2 5) 

To run with a given file that is redirected to standard input:

./test_points2 < test_input_file.txt
