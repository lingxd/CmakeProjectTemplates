# Once done, this will define                                                                                                                                                                  
#                                                                               
#  SPDLOG_INCLUDE_DIR - the SPDLOG include directory                            
#  SPDLOG_LIBRARY_DIR - the SPDLOG library directory                            
#  SPDLG_LIBS - link these to use SPDLOG                                        
#                                                                               
#  ......                                                      

MACRO(LOAD_LIBSPDLOG os arch)                                                   
    SET(3RDPARTY_DIR ${PROJECT_SOURCE_DIR}/3rdparty/target/${${os}}_${${arch}}) 
    MESSAGE(STATUS "3RDPARTY_DIR: ${3RDPARTY_DIR}")                             
    FIND_FILE(SPDLOG_INCLUDE_DIR include ${3RDPARTY_DIR} NO_DEFAULT_PATH)          
    FIND_FILE(SPDLOG_LIBRARY_DIR lib ${3RDPARTY_DIR} NO_DEFAULT_PATH)           
                                                                                
    SET(SPDLOG_LIBS                                                             
        spdlog
        pthread
        #PARENT_SCOPE no parent                                                 
    )                                                                           
    IF(SPDLOG_INCLUDE_DIR)                                                      
        SET(SPDLOG_LIBRARY_DIR "${SPDLOG_LIBRARY_DIR}/spdlog")                  
        MESSAGE(STATUS "SPDLOG_INCLUDE_DIR : ${SPDLOG_INCLUDE_DIR}")            
        MESSAGE(STATUS "SPDLOG_LIBRARY_DIR : ${SPDLOG_LIBRARY_DIR}")            
        MESSAGE(STATUS "SPDLOG_LIBS : ${SPDLOG_LIBS}")                          
    ELSE()                                                                      
        MESSAGE(FATAL_ERROR "SPDLOG_LIBS not found!")                           
    ENDIF()                                                                     
ENDMACRO()