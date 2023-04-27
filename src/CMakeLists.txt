
#main 
add_executable(robolliurex main.cpp robocore.cpp robomenus.cpp robopilot.cpp roboslot.cpp robowidgets.cpp rsrcmanager.cpp)

#require pkg-config support
find_package(PkgConfig REQUIRED)

#required pkg-config libs
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

find_package(EdupalsBase REQUIRED)
find_package(LliurexLGI REQUIRED)

include_directories(${GTK3_INCLUDE_DIRS})

target_link_libraries(robolliurex pthread Edupals::Base Lliurex::LGI ${GTK3_LIBRARIES})

#add include dirs
include_directories(${CMAKE_SOURCE_DIR}/include)


install(TARGETS robolliurex RUNTIME DESTINATION bin)

