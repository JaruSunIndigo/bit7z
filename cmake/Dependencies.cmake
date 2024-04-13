# Downloading the CPM.cmake package manager
set( CPM_DOWNLOAD_VERSION 0.38.7 )
set( CPM_DOWNLOAD_HASH 83e5eb71b2bbb8b1f2ad38f1950287a057624e385c238f6087f94cdfc44af9c5 )
set( CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake" )
set( CPM_USE_NAMED_CACHE_DIRECTORIES ON )
if( NOT ( EXISTS ${CPM_DOWNLOAD_LOCATION} ) )
    message( STATUS "Downloading CPM.cmake to ${CPM_DOWNLOAD_LOCATION}" )
    file( DOWNLOAD
          https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
          ${CPM_DOWNLOAD_LOCATION}
          SHOW_PROGRESS
          EXPECTED_HASH SHA256=${CPM_DOWNLOAD_HASH}
    )
endif()
include( ${CPM_DOWNLOAD_LOCATION} )

# No custom path to 7-Zip's source code was specified by the user, so we download it.
if( BIT7Z_CUSTOM_7ZIP_PATH STREQUAL "" )
    if ( BIT7Z_BUILD_FOR_P7ZIP )
        # p7zip source code (calling the package as 7-zip just for simplify the code).
        CPMAddPackage( NAME 7-zip
                       GITHUB_REPOSITORY "rikyoz/p7zip"
                       VERSION ${BIT7Z_7ZIP_VERSION}
                       DOWNLOAD_ONLY YES )
    else()
        # 7-zip source code
        CPMAddPackage( NAME 7-zip
                       GITHUB_REPOSITORY "rikyoz/7-Zip"
                       VERSION ${BIT7Z_7ZIP_VERSION}
                       DOWNLOAD_ONLY YES )
    endif()
    if( 7-zip_ADDED )
        message( STATUS "7-zip source code available at ${7-zip_SOURCE_DIR}" )
        add_library( 7-zip INTERFACE IMPORTED )
        target_include_directories( 7-zip INTERFACE "${7-zip_SOURCE_DIR}/CPP/" )
    endif()
endif()

# ghc::filesystem library
if( NOT USE_STANDARD_FILESYSTEM OR NOT STANDARD_FILESYSTEM_COMPILES OR BIT7Z_BUILD_TESTS )
    CPMAddPackage( NAME ghc_filesystem
                   GITHUB_REPOSITORY rikyoz/filesystem
                   GIT_TAG 983650f374699e3979f9cdefe13ddff60bd4ac68
                   DOWNLOAD_ONLY YES )
    if( ghc_filesystem_ADDED )
        message( STATUS "ghc::filesystem source code available at ${ghc_filesystem_SOURCE_DIR}" )
        add_library( ghc_filesystem INTERFACE IMPORTED )
        target_include_directories( ghc_filesystem SYSTEM INTERFACE ${ghc_filesystem_SOURCE_DIR}/include )
    endif()
endif()
