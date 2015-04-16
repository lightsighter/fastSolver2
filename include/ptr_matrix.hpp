#ifndef _ptr_matrix_hpp
#define _ptr_matrix_hpp

#include <iostream>
#include <string>

// The motivation is to encapsulate various matrix interpretation
//  from pointers.
// This matrix can work on data by existing pointers and provide
//  the wrapper for linear algebra operations with blas and lapack.
class PtrMatrix {
public:
  PtrMatrix();
  PtrMatrix(int, int);
  PtrMatrix(int, int, int, double*, char trans='n');
  ~PtrMatrix();
  
  void rand(long seed);
  void display(const std::string&);

  int rows() const;
  int cols() const;
  int LD() const;
  double* pointer() const;
  double* pointer(int, int);

  void solve(PtrMatrix&);

  // set all entries to value
  void clear(double value);

  // scale all entries
  void scale(double value);
  
  static void add
  (double alpha, const PtrMatrix&,
   double beta,  const PtrMatrix&,
   PtrMatrix&);
  
  static void gemm
  (const PtrMatrix&, const PtrMatrix&, const PtrMatrix&, PtrMatrix&);
  
  //friend std::ostream& operator<< (std::ostream& stream, const PtrMatrix&);

private:
  // helper function
  // return entry/reference to the matrix entry
  double  operator()(int, int) const;
  double& operator()(int, int);

  // private variables  
  int mRows;
  int mCols;
  int leadD; // leading dimension
  double *ptr;
  bool has_memory;
  
public:
  // 't' for transpose, 'n' for no transpose
  // only be used in gemm
  char trans; 
};

#endif