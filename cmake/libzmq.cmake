# Once done, this will define                                                                                                                                                                  
#                                                                               
#  LIBZMQ_INCLUDE_DIR - the LIBZMQ include directory                            
#  LIBZMQ_LIBRARY_DIR - the LIBZMQ library directory                            
#  LIBZMQ_LIBS - link these to use LIBZMQ                                        
#                                                                               
#  ......                                                      

MACRO(LOAD_LIBLIBZMQ os arch)                                                   
    SET(3RDPARTY_DIR ${PROJECT_SOURCE_DIR}/3rdparty/target/${${os}}_${${arch}}) 
    MESSAGE(STATUS "3RDPARTY_DIR: ${3RDPARTY_DIR}")                             
    FIND_FILE(LIBZMQ_INCLUDE_DIR include ${3RDPARTY_DIR} NO_DEFAULT_PATH)          
    FIND_FILE(LIBZMQ_LIBRARY_DIR lib ${3RDPARTY_DIR} NO_DEFAULT_PATH)           
                                                                                
    SET(LIBZMQ_LIBS                                                             
        zmq
        #PARENT_SCOPE no parent                                                 
    )                                                                           
    IF(LIBZMQ_INCLUDE_DIR)                                                      
        SET(LIBZMQ_LIBRARY_DIR "${LIBZMQ_LIBRARY_DIR}/libzmq")                  
        MESSAGE(STATUS "LIBZMQ_INCLUDE_DIR : ${LIBZMQ_INCLUDE_DIR}")            
        MESSAGE(STATUS "LIBZMQ_LIBRARY_DIR : ${LIBZMQ_LIBRARY_DIR}")            
        MESSAGE(STATUS "LIBZMQ_LIBS : ${LIBZMQ_LIBS}")                          
    ELSE()                                                                      
        MESSAGE(FATAL_ERROR "LIBZMQ_LIBS not found!")                           
    ENDIF()                                                                     
ENDMACRO()