/*=========================================================================

  Program:   Visualization Library
  Module:    Pixmap.hh
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
// .NAME vlPixmap - scalar data in RGB (color) form
// .SECTION Description
// vlPixmap is a concrete implementation of vlScalars. Scalars are
// represented using three values for color (red, green, blue). Each of
// r,g,b ranges from (0,255) (i.e., an unsigned char value).

#ifndef __vlPixmap_h
#define __vlPixmap_h

#include "CoScalar.hh"
#include "CArray.hh"

class vlPixmap : public vlColorScalars 
{
public:
  vlPixmap() {};
  ~vlPixmap() {};
  vlPixmap(const vlPixmap& fs) {this->S = fs.S;};
  vlPixmap(const int sz, const int ext=1000):S(3*sz,3*ext){};
  int Allocate(const int sz, const int ext=1000) {return this->S.Allocate(3*sz,3*ext);};
  void Initialize() {this->S.Initialize();};
  char *GetClassName() {return "vlPixmap";};

  // vlScalar interface
  vlScalars *MakeObject(int sze, int ext=1000);
  int GetNumberOfScalars() {return (this->S.GetMaxId()+1)/3;};
  void Squeeze() {this->S.Squeeze();};
  int GetNumberOfValuesPerPoint() {return 3;};

  // miscellaneous
  vlPixmap &operator=(const vlPixmap& fs);
  void operator+=(const vlPixmap& fs) {this->S += fs.S;};
  void Reset() {this->S.Reset();};
  unsigned char *WriteInto(int id, int number);

  // vlColorScalar interface.
  unsigned char *GetColor(int id);
  void GetColor(int id, unsigned char rgb[3]);
  void SetColor(int id, unsigned char rgb[3]);
  void InsertColor(int id, unsigned char rgb[3]);
  int InsertNextColor(unsigned char rgb[3]);

protected:
  vlCharArray S;
};

// Description:
// Return a rgb triplet at array location i.
inline unsigned char *vlPixmap::GetColor(int i) {return this->S.GetPtr(3*i);};

// Description:
// Set a rgb value at a particular array location. Does not do range 
// checking.
inline void vlPixmap::SetColor(int i, unsigned char rgb[3]) 
{
  i *= 3; 
  this->S[i] = rgb[0]; 
  this->S[i+1] = rgb[1]; 
  this->S[i+2] = rgb[2];
}

// Description:
// Insert a rgb value at a particular array location. Does range checking
// and will allocate additional memory if necessary.
inline void vlPixmap::InsertColor(int i, unsigned char *rgb) 
{
  this->S.InsertValue(3*i+2, rgb[2]);
  this->S[3*i] = rgb[0];
  this->S[3*i+1] = rgb[1];
}

// Description:
// Insert a rgb value at the next available slot in the array. Will allocate
// memory if necessary.
inline int vlPixmap::InsertNextColor(unsigned char *rgb) 
{
  int id = this->S.GetMaxId() + 3;
  this->S.InsertValue(id,rgb[2]);
  this->S[id-2] = rgb[0];
  this->S[id-1] = rgb[1];
  return id/3;
}

// Description:
// Get pointer to data. Useful for direct writes into object. MaxId is bumped
// by number (and memory allocated if necessary).
inline unsigned char *vlPixmap::WriteInto(int id, int number)
{
  return this->S.WriteInto(id, number);
}

#endif
