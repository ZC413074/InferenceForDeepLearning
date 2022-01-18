cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(MyAlgorithm)
add_library(${PROJECT_NAME} SHARED)
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
	message("OPENMP FOUND")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
	set(CMAKE_EXE_LINKER_FLAGS"${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

set(CUDA_PATH "$ENV{LIBRARY_INSTALL_PATH}/cuda")
if(CUDA)
 target_include_directories(${PROJECT_NAME} PRIVATE ${CUDA_PATH}/include) 
 target_link_directories(${PROJECT_NAME} PRIVATE ${CUDA_PATH}/lib/x64)
 file(GLOB CUDA_LIBRARIES "${CUDA_PATH}/lib/x64/*.lib")  #批量添加
endif()

#opencv
list(APPEND CMAKE_MODULE_PATH "$ENV{LIBRARY_INSTALL_PATH}/share")
option(USE_OPENCV "Use USE_OPENCV support" ON)
if(USE_OPENCV)
	FIND_PACKAGE(OpenCV REQUIRED)
	if(OpenCV_FOUND)
		target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
		target_link_directories(${PROJECT_NAME} PRIVATE ${OpenCV_LINK_DIRECTORIES})
		message(STATUS"OPENCV FOUND")
	else()
		message(FATAL_ERROR"OPENCV NOT FOUND")
	endif()
endif()

#openvino
option(USE_OPENVINO "Use USE_OPENVINO support" ON)
set(InferenceEngine_DIR F:/the3rdparty/libraries/openvino_2021_4_582/deployment_tools/inference_engine/share)
set(ngraph_DIR F:/the3rdparty/libraries/openvino_2021_4_582/deployment_tools/ngraph/cmake)
if(USE_OPENVINO)
	FIND_PACKAGE(InferenceEngine REQUIRED)
	if(InferenceEngine_FOUND)
		target_include_directories(${PROJECT_NAME} PRIVATE ${InferenceEngine_INCLUDE_DIRS})
		message(STATUS"InferenceEngine FOUND")
	else()
		message(FATAL_ERROR"InferenceEngine NOT FOUND")
	endif()
endif()

if(USE_OPENVINO)
	find_package(ngraph REQUIRED)
	if(ngraph_FOUND)
		message(STATUS"ngraph FOUND")
	else()
		message(FATAL_ERROR"ngraph NOT FOUND")
	endif()
endif()

FILE(GLOB_RECURSE SOURCES *.cpp *.c *.h *.hpp *.cu)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ./)
target_include_directories(${PROJECT_NAME} PRIVATE ./Json)
target_include_directories(${PROJECT_NAME} PRIVATE ./FileOperation)
target_include_directories(${PROJECT_NAME} PRIVATE ./Inference)

target_link_libraries(${PROJECT_NAME} PRIVATE ${InferenceEngine_LIBRARIES} ${NGRAPH_LIBRARIES} ${CUDA_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBRARIES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
target_compile_definitions(${PROJECT_NAME} PRIVATE ALGORITHM_EXPORT)
target_compile_definitions(${PROJECT_NAME} PRIVATE  UNICODE _UNICODE)
target_compile_definitions(${PROJECT_NAME} PRIVATE CMAKE_DEBUG_POSTFIX="d")

################################################################
# 根据编译的debug与release自动生成对应的文件夹，以及将exe放入其中
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