cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lopengl32 -lglu32 -lfreeglut")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11 -lopengl32 -lglu32 -lfreeglut")

find_package(OpenGL)
find_package(GLUT)

include_directories(freeglut/bin)
include_directories(freeglut/lib)
include_directories(freeglut/include/GL)
link_directories(freeglut/bin)

aux_source_directory(. SRC_LIST)

set(SOURCE_FILES main.cpp)
add_executable(untitled ${SOURCE_FILES})
#target_link_libraries(untitled libfreeglut.a)
add_executable(triangle triangle.c)
add_executable(hexagon hexagon.c)
add_executable(house house.c)
add_executable(prims cmake-build-debug/prims.c)
add_executable(mousekeyboard mousekeyboard.c)
add_executable(ddaandbresonims ddaandbresonims.c)
add_executable(ddabres ddabres.c)
add_executable(subwid subwid.c)
add_executable(liangbarsky liangbarsky.c)
add_executable(MazeGenerator MazeGenerator.c)
add_executable(pointclip pointclip.c)
add_executable(cohenland cohenland.c)
add_executable(subwidcomplex subwidcomplex.c)
add_executable(leaf leaf.c)
add_executable(fractal fractal.c)
add_executable(fractalsquare fractalsquare.c)
add_executable(transformation transformation.c)
add_executable(oopsconcept oopsconcept.cpp)
add_executable(pong pong.cpp)
add_executable(pongpong pongpong.c)

target_link_libraries(
        pongpong
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )


target_link_libraries(
        pong
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )

target_link_libraries(
        transformation
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )

target_link_libraries(
        fractalsquare
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )

target_link_libraries(
        fractal
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )

target_link_libraries(
        leaf
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )

target_link_libraries(
        subwidcomplex
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )

target_link_libraries(
        cohenland
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )

target_link_libraries(
        MazeGenerator
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )

target_link_libraries(
        pointclip
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )




target_link_libraries(
        liangbarsky
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )

target_link_libraries(
        subwid
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )


target_link_libraries(
        mousekeyboard
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )

target_link_libraries(
        ddabres
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )

target_link_libraries(
        ddaandbresonims
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )



target_link_libraries(
        prims
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )


target_link_libraries(
        house
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )

target_link_libraries(
        triangle
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )

target_link_libraries(
        hexagon
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES} )



















