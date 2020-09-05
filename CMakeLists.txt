CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

PROJECT(SegmentSandbox)

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}/include/
)

SET(CMAKE_CXX_STANDARD 17)

SET(SRC_LIST
    ${PROJECT_SOURCE_DIR}/src/sandbox.cc
    ${PROJECT_SOURCE_DIR}/src/containerfs.cc
    ${PROJECT_SOURCE_DIR}/src/userns.cc
    ${PROJECT_SOURCE_DIR}/src/cgroup/subsys.cc
    ${PROJECT_SOURCE_DIR}/src/cgroup/unit.cc
)

SET(HEADER_INCLUDE_DIR include/ssandbox)

SET(HEADER_LIST
    ${HEADER_INCLUDE_DIR}/containerfs.h 
    ${HEADER_INCLUDE_DIR}/sandbox.h 
    ${HEADER_INCLUDE_DIR}/userns.h 
    ${HEADER_INCLUDE_DIR}/cgroup.h 
)

FIND_PACKAGE(PkgConfig)

PKG_SEARCH_MODULE(FMT REQUIRED fmt)

LINK_LIBRARIES(
    ${FMT_LIBRARIES}
    pthread
)

ADD_LIBRARY(ssandbox STATIC ${SRC_LIST})

INSTALL(TARGETS ssandbox
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)

INSTALL(FILES ${HEADER_LIST} DESTINATION include/ssandbox)