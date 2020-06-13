# Once done, this will define                                                                                                                                                                  
#                                                                               
#  SERIAL_INCLUDE_DIR - the SERIAL include directory                            
#  SERIAL_LIBRARY_DIR - the SERIAL library directory                            
#  SERIAL_LIBS - link these to use SERIAL                                        
#                                                                               
#  ......                                                      

MACRO(LOAD_LIBSERIAL os arch)                                                   
    SET(3RDPARTY_DIR ${PROJECT_SOURCE_DIR}/3rdparty/target/${${os}}_${${arch}}) 
    MESSAGE(STATUS "3RDPARTY_DIR: ${3RDPARTY_DIR}")                             
    FIND_FILE(SERIAL_INCLUDE_DIR include ${3RDPARTY_DIR} NO_DEFAULT_PATH)          
    FIND_FILE(SERIAL_LIBRARY_DIR lib ${3RDPARTY_DIR} NO_DEFAULT_PATH)           
                                                                                
    SET(SERIAL_LIBS                                                             
        serial
        #PARENT_SCOPE no parent                                                 
    )                                                                           
    IF(SERIAL_INCLUDE_DIR)                                                      
        SET(SERIAL_LIBRARY_DIR "${SERIAL_LIBRARY_DIR}/serial")                  
        MESSAGE(STATUS "SERIAL_INCLUDE_DIR : ${SERIAL_INCLUDE_DIR}")            
        MESSAGE(STATUS "SERIAL_LIBRARY_DIR : ${SERIAL_LIBRARY_DIR}")            
        MESSAGE(STATUS "SERIAL_LIBS : ${SERIAL_LIBS}")                          
    ELSE()                                                                      
        MESSAGE(FATAL_ERROR "SERIAL_LIBS not found!")                           
    ENDIF()                                                                     
ENDMACRO()