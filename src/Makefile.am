bin_PROGRAMS = oglproject
oglproject_SOURCES = oglproject.cpp ugl_engine.cpp ugl_ctexture.cpp ugl_clight.cpp ugl_md2mesh.cpp ugl_cmesh.cpp

# set the include path found by configure
INCLUDES= $(all_includes)

# the library search path.
oglproject_LDFLAGS = -all-static -no-undefined $(all_libraries)

oglproject_LDADD = -lpthread -lSDL -lGL -lGLU
noinst_HEADERS = ugl_engine.h umangagl.h ugl_ctexture.h ugl_clight.h ugl_md2mesh.h ugl_cmesh.h
