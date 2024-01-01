cmake_minimum_required(VERSION 3.14)

# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
	cmake_policy(SET CMP0135 NEW)
endif()

include(FetchContent)
FetchContent_Declare(
		googletest
		URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

set(SOURCE test.cpp services/personen_service_impl_test.cpp services/personen_service_impl_test.h)



# Create test executable
add_executable(PersonenServiceProjektTest ${SOURCE} ${HEADER}  )

target_link_libraries(
		PersonenServiceProjektTest
		GTest::gtest_main
		GTest::gmock
)

include(GoogleTest)
gtest_discover_tests(PersonenServiceProjektTest)



# Mark it as test executable for CMake
add_test(NAME PersonenServiceProjektTest COMMAND BlankCMakeProjectTest)

# Push it to tests
set_target_properties(PersonenServiceProjektTest PROPERTIES FOLDER Tests)

# Build tests where other libraries reside
set_target_properties(PersonenServiceProjektTest
		PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>"
)