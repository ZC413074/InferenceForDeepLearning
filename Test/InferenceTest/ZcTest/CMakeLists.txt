cmake_minimum_required(VERSION 3.13)
add_executable(${PROJECT_NAME})
if(WIN32)
	SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CMAKE_CXX_FLAGS_DEBUG}  -O0 -Wall -g /Zi /Gm")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -Wall -g /Zi")
	set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
elseif(UNIX)
	set(CMAKE_CXX_VISIBILITY_PRESET hidden)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
endif()

FIND_PACKAGE( OpenMP REQUIRED)
if(OPENMP_FOUND)
	message(STATUS"${PROJECT_NAME}:OPENMP FOUND")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
	set(CMAKE_EXE_LINKER_FLAGS"${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS} ")
endif()


FILE(GLOB_RECURSE SOURCES *.cpp *.c *.h *.hpp *.cu)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE Inference)
target_include_directories(${PROJECT_NAME} PRIVATE ./../../../Algorithm  ./../../../Algorithm/Inference)

################################################################
# 根据编译的debug与release自动生成对应的文件夹，以及将exe放入其中
#target_compile_definitions(${PROJECT_NAME} PRIVATE EXECUTABLE_OUTPUT_PATH=${PROJECT_BINARY_DIR}/../)  
#target_compile_definitions(${PROJECT_NAME} PRIVATE LIBRARY_OUTPUT_PATH=${PROJECT_BINARY_DIR}/../)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../)  
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../)
install(TARGETS ${PROJECT_NAME}
		CONFIGURATIONS Release 
        RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/install/release
        LIBRARY DESTINATION ${PROJECT_BINARY_DIR}/install/release
        ARCHIVE DESTINATION ${PROJECT_BINARY_DIR}/install/release)		
install(TARGETS ${PROJECT_NAME}
		CONFIGURATIONS Debug
        RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/install/debug
        LIBRARY DESTINATION ${PROJECT_BINARY_DIR}/install/debug
        ARCHIVE DESTINATION ${PROJECT_BINARY_DIR}/install/debug)