set(HEADER_FILES
		inc/recursion.h
	)

set(SOURCE_FILES
		src/recursion.cpp
        )
include_directories(inc)
add_library(lab7_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
