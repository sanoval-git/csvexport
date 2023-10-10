cmake_minimum_required(VERSION 3.16)

project(csvexport)

# Результирующая директория
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/result)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lib)

# Устанавливаем дефайны для сборки
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${OpenMP_CXX_FLAGS}")

find_package(Qt5 REQUIRED COMPONENTS Core Gui)

include_directories(include)

add_executable(csvexport
    source/main.cpp
    source/exporter.cpp
    source/csv_builder.cpp
    source/acqus_scanner.cpp
    )

target_link_libraries(csvexport PRIVATE
    Qt5::Core
    Qt5::Gui
    )

# Настройки deb-пакета
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER sanoval)
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})

install(TARGETS csvexport
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

IF(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS)
    INSTALL(PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION bin COMPONENT System)
ENDIF(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS)

include(InstallRequiredSystemLibraries)

include(CPack)
