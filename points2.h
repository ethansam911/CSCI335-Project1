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
	{}


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
  Points2& operator=(const Points2 &rhs)
  {
	Points2 copy = rhs; 
	std::swap(*this, copy);
	return *this; 
  }

  // Move-constructor. 
	Points2(Points2 &&rhs): sequence_{rhs.sequence_}
	{
	 rhs.sequence_ = nullptr;
	}
		  

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

  // One parameter constructor.
  //This one array holds two objects
  //This is one coordinate aka two values
  Points2(const std::array<Object, 2>& item) 
  {
	item[0] = 0;
	item[1] = 0;
	size_ = 1    
  }

  // Read a chain from standard input.
  void ReadPoints2() {
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
	size_ = size_of_sequence;
	std::array<int, 2> *sequence_;
	
    
    Object token;
    for (int i = 0 ;input_stream >> token; ++i) {
      // Read coordinates.
	  int coordinate_x;
	  int coordinate_y;
	  input_stream >> coordinate_x >> coordinate_y;
      // Fill sequence_ here.
	  for( size_t i = 0; i < size_; ++i)
	  {		  
	  sequence_[i] =  
	  
	  
    }
    
  }

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
  } //END operator[]
  
 //  @c1: A sequence.
 //  @c2: A second sequence.
 //  @return their sum. If the sequences are not of the same size, append the
 //    result with the remaining part of the larger sequence.
 friend Points2 operator+(const Points2 &c1, const Points2 &c2) 
 {
   // Code missing - IN PROGRESS
   
   if( c1 > c2)
   {
	   
   
   }
   else if (c2 > c1)
   {
	   
	   
   }
   
 }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Points2 &some_points2) 
 {
   // Code missing.
 }
 
 private:
  // Sequence of points. 
  //Fixed size array container of size 2; holds objects 
  //*sequence_ is a pointer to a memory location with an array holding three objects
  std::array<Object, 2> *sequence_;
  // Size of sequence.
  size_t size_;

};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2_H_
