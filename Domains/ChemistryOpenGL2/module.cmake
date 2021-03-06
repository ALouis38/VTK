vtk_module(vtkDomainsChemistryOpenGL2
  TCL_NAME
    vtkRenderingChemistryOpenGLII
  DEPENDS
    vtkRenderingOpenGL2
  IMPLEMENTS
    vtkDomainsChemistry
  BACKEND
    OpenGL2
  IMPLEMENTATION_REQUIRED_BY_BACKEND
  PRIVATE_DEPENDS
    vtkglew
  KIT
    vtkOpenGL
  TEST_DEPENDS
    vtkTestingCore
    vtkTestingRendering
    vtkInteractionStyle
    vtkRendering${VTK_RENDERING_BACKEND}
    ${extra_opengl_depend}
  )
