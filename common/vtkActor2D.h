/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkActor2D.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$
  Thanks:    Thanks to Matt Turek who developed this class.

Copyright (c) 1993-1998 Ken Martin, Will Schroeder, Bill Lorensen.

This software is copyrighted by Ken Martin, Will Schroeder and Bill Lorensen.
The following terms apply to all files associated with the software unless
explicitly disclaimed in individual files. This copyright specifically does
not apply to the related textbook "The Visualization Toolkit" ISBN
013199837-4 published by Prentice Hall which is covered by its own copyright.

The authors hereby grant permission to use, copy, and distribute this
software and its documentation for any purpose, provided that existing
copyright notices are retained in all copies and that this notice is included
verbatim in any distributions. Additionally, the authors grant permission to
modify this software and its documentation for any purpose, provided that
such modifications are not distributed without the explicit consent of the
authors and that existing copyright notices are retained in all copies. Some
of the algorithms implemented by this software are patented, observe all
applicable patent law.

IN NO EVENT SHALL THE AUTHORS OR DISTRIBUTORS BE LIABLE TO ANY PARTY FOR
DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
OF THE USE OF THIS SOFTWARE, ITS DOCUMENTATION, OR ANY DERIVATIVES THEREOF,
EVEN IF THE AUTHORS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

THE AUTHORS AND DISTRIBUTORS SPECIFICALLY DISCLAIM ANY WARRANTIES, INCLUDING,
BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE, AND NON-INFRINGEMENT.  THIS SOFTWARE IS PROVIDED ON AN
"AS IS" BASIS, AND THE AUTHORS AND DISTRIBUTORS HAVE NO OBLIGATION TO PROVIDE
MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.


=========================================================================*/
// .NAME vtkActor2D
// .SECTION Description
// vtkActor2D is similar to vtkActor, but it is made to be used with
// two dimensional images and annotation.  vtkActor2D has a position, 
// orientation, and scale, but does not use a transformation matrix 
// like vtkActor.  vtkActor2D also has a layer property which allows two
// dimensional actors to be rendered on top of each other in a certain
// order.  vtkActor2D has a reference to a vtkMapper2D object which does
// the rendering.

// .SECTION See Also
// vtkProperty2D  vtkMapper2D

#ifndef __vtkActor2D_h
#define __vtkActor2D_h

#include "vtkReferenceCount.h"
#include "vtkCoordinate.h"

class vtkMapper2D;
class vtkProperty2D;


class VTK_EXPORT vtkActor2D : public vtkReferenceCount
{
public:

  vtkActor2D();
  ~vtkActor2D();

  static vtkActor2D* New() {return new vtkActor2D;};
  void PrintSelf(ostream& os, vtkIndent indent);
  const char *GetClassName() {return "vtkActor2D";};

  void Render(vtkViewport *viewport);

  vtkSetObjectMacro(Mapper, vtkMapper2D);

  vtkSetVector2Macro(Scale, float);
  vtkGetVectorMacro(Scale, float, 2);

  vtkSetMacro(Orientation, float);
  vtkGetMacro(Orientation, float);

  vtkSetMacro(LayerNumber, int);
  vtkGetMacro(LayerNumber, int);

  vtkSetMacro(Visibility, int);
  vtkGetMacro(Visibility, int);
  vtkBooleanMacro(Visibility, int);

  vtkProperty2D* GetProperty();
  vtkSetObjectMacro(Property, vtkProperty2D);

  // Description:
  // Get the PositionCoordinate instance of vtkCoordinate
  // This is used for for complicated or relative positioning
  vtkViewportCoordinateMacro(Position);
  
  void SetDisplayPosition(int,int);
  
  unsigned long int GetMTime();//overload superclasses' implementation

protected:
  float Orientation;
  float Scale[2];

  int LayerNumber;
  int Visibility;
  int SelfCreatedProperty;

  vtkProperty2D *Property;
  vtkMapper2D *Mapper;
  vtkCoordinate *PositionCoordinate;
};

#endif


