// --> YOUR NAME here
//Name: Ethan Sam 
// Few comments describing the class Points2

#ifndef CSCI335_HOMEWORK1_POINTS2_H_
#define CSCI335_HOMEWORK1_POINTS2_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {
// Place comments that provide a brief explanation of the class,
// and its sample usage.
// The Class Points2 accepts coordinates as parameters  
template<typename Object>
class Points2 {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor. 
  // Set size to 0.
  // Points2() = default; PREVIOUS CODE
 
	Points2()
	{
		size_ = 0;
	}

	// Copy-constructor.
	Points2(const Points2 &rhs)
	{
		
	}


  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Points2 copy = rhs; 
  // std::swap(*this, copy);
  // return *this;
  // }
  //"this" refers to the current instance of the class
  //We overload the "=" operator to accept new coordinates 
  /*The "this" pointer is an implicit parameter to all member functions 
	(This may be used to refer to the invoking object
  */
  Points2& operator=(const Points2 &rhs)
  {
	Points2 copy = rhs; 
	std::swap(*this, copy);
	return *this; 
  }// END operator "="

  // Move-constructor.
//rhs.sequence is a synonym of sequence_ (unupdated)
	Points2(Points2 &&rhs): sequence_{rhs.sequence_}
	{
	 rhs.sequence_ = nullptr;
	}// END Move constructor
		  

  // Move-assignment.
  // Just use std::swap() for all variables.
  
  Points2& operator=(Points2 &&rhs)
  {	
	//When overloading the "=" operator, the size of a given sequence may vary 
	if(size_ != rhs.size())
	{	  
		std::swap(size_, rhs.size_);
	}
	std::swap(sequence_, rhs.sequence_);
  }// END Move-assignment
  
//Destructor
  ~Points2()
  {
	  if(sequence_ != nullptr)
	  {
		delete[] sequence_;
		sequence_ = nullptr;
	  }
  }//END destructor

  // End of big-five.

  // One parameter constructor._
  //This one array holds two objects
  //An object can be either a double or integer
  // item and squence are both of type array (both hold two objects)
  
  Points2(const std::array<Object, 2>& item) 
  {
	  // item is of type std::array<Object, 2>&, we must change sequence so it is the same
	  sequence_ = new std::array<Object, 2>{item}; 
	  size_ = item.size()/2;
  }
/*
  // Read a chain from standard input.
  void ReadPoints2() 
  {
    // Part of code included (without error checking).
    std::string input_line;
    std::getline(std::cin, input_line); 
    std::stringstream input_stream(input_line);
    if (input_line.empty()) return;
    // Read size of sequence (an integer).
    int size_of_sequence;
    input_stream >> size_of_sequence;
    // Allocate space for sequence.
    // Add code here.
	
	const int num_of_points = size_of_sequence;
	std::array<std::array<int, 2>, num_of_points> coord_sequence;
	//Object is the template type parameter (i.e int, double, etc.)
    Object token;
	// Read coordinates.
    for (auto i = 0 ;input_stream >> token; ++i) 
	{
		for(auto pos = 0; pos < 2 ; ++pos)
		{
		     // Fill sequence_ here.
			sequence_[pos] = coord_sequence[i][pos] = token;
		}
	}  
	
  }
*/
  size_t size() const 
  {
    // Code missing.
	return size_;
	
  }

  // @location: an index to a location in the sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
  const std::array<Object, 2>& operator[](size_t location) const 
  { 
	if((location > size_)||(location < 0))
	{	  
		abort();
	}
	else
	{
		return sequence_[location];
	}
	return sequence_[location];
  } //END operator[]
  
 //  @c1: A sequence.
 //  @c2: A second sequence.
 //  @return their sum. If the sequences are not of the same size, append the
 //    result with the remaining part of the larger sequence.
 friend Points2 operator+(const Points2 &c1, const Points2 &c2) 
 {
   // Code missing - IN PROGRESS


 
 }


 // Overloading the << operatori
 //This is a string remember
  friend std::ostream &operator<<(std::ostream &out, const Points2 &some_points2) 
 {
	const std::array<Object, 2> new_array = *some_points2.sequence_;
 
    out << "(" << new_array[0] << ", " << new_array[1] << ")";

	return out;
 }

 
 private:
  // Sequence of points. 
  //Fixed size array container of size 2; holds objects 
  //*sequence_ is a pointer to a memory location with an array holding two objects (int or double)
  std::array<Object, 2> *sequence_;
  // Size of sequence.
  size_t size_;

};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2_H_
