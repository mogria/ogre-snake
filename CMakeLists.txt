cmake_minimum_required(VERSION 2.8)
project(OGRESNAKE)
set(OGRESNAKE_SOURCE_PATH ${OGRESNAKE_SOURCE_DIR}/src)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
	
# find all dependencies
find_package(OGRE REQUIRED)
find_package(OIS REQUIRED)
find_package(Bullet REQUIRED)
find_package(OgreBullet REQUIRED)

message(${OgreBullet_LIBRARIES})

# GUI Type
if(WIN32)
  set(GUI_TYPE WIN32)
endif(WIN32)
if(APPLE)
  set(GUI_TYPE MACOSX_BUNDLE)
endif(APPLE)

# compose include path and libraries of the used ogre components
if(UNIX)
  set(RENDER_SYSTEM RenderSystem_GL)
elseif(WIN32)
  set(RENDER_SYSTEM RenderSystem_Direct3D11)
endif()

set(USED_OGRE_COMPONENTS Overlay;Terrain;${RENDER_SYSTEM})
set(ALL_OGRE_INCLUDE_DIRS ${OGRE_INCLUDE_DIRS})
set(ALL_OGRE_LIBS ${OGRE_LIBRARIES})

foreach(component ${USED_OGRE_COMPONENTS})
  set(ALL_OGRE_INCLUDE_DIRS ${ALL_OGRE_INCLUDE_DIRS};${OGRE_${component}_INCLUDE_DIRS})
  set(ALL_OGRE_LIBS ${ALL_OGRE_LIBS};${OGRE_${component}_LIBRARIES})
endforeach()

# include directories
include_directories(${ALL_OGRE_INCLUDE_DIRS})
include_directories(${OIS_INCLUDE_DIRS})
include_directories(${BULLET_INCLUDE_DIRS})
include_directories(${OgreBullet_INCLUDE_DIRS})

# ogresnake project, create executable out of all source files in src/
file(GLOB_RECURSE OGRESNAKE_SOURCE_FILES ${OGRESNAKE_SOURCE_PATH}/*.cpp)
if(UNIX)
  add_executable(ogresnake ${OGRESNAKE_SOURCE_FILES})
else()
  add_executable(ogresnake ${GUI_TYPE} ${OGRESNAKE_SOURCE_FILES})
endif()

# copy plattform specific resources (plugins.cfg)
configure_file("${OGRESNAKE_SOURCE_PATH}/config/plugins.cfg.in"
               "${OGRESNAKE_BINARY_DIR}/plugins.cfg")

configure_file("${OGRESNAKE_SOURCE_PATH}/config/resources.cfg.in"
               "${OGRESNAKE_BINARY_DIR}/resources.cfg")

file(COPY ${OGRESNAKE_SOURCE_DIR}/media DESTINATION ${OGRESNAKE_BINARY_DIR})

if(UNIX)
  target_link_libraries(ogresnake ${ALL_OGRE_LIBS} ${OIS_LIBRARIES} ${BULLET_LIBRARIES} ${OgreBullet_LIBRARIES})
endif()
if(WIN32)
  target_link_libraries(ogresnake ${ALL_OGRE_LIBS} ${OIS_LIBRARIES} ${BULLET_LIBRARIES} ${OgreBullet_LIBRARIES})
endif()
