IF(NOT WIN32)                                
    STRING(ASCII 27 Esc)                                                        
    SET(ColourReset "${Esc}[m")                                                 
    SET(ColourBold  "${Esc}[1m")                                                
    SET(Red         "${Esc}[31m")                                               
    SET(Green       "${Esc}[32m")                                               
    SET(Yellow      "${Esc}[33m")                                               
    SET(Blue        "${Esc}[34m")                                               
    SET(MAGENTA     "${Esc}[35m")                                               
    SET(Cyan        "${Esc}[36m")                                               
    SET(White       "${Esc}[37m")                                               
    SET(BoldRed     "${Esc}[1;31m")                                             
    SET(BoldGreen   "${Esc}[1;32m")                                             
    SET(BoldYellow  "${Esc}[1;33m")                                             
    SET(BOLDBLUE    "${Esc}[1;34m")                                             
    SET(BOLDMAGENTA "${Esc}[1;35m")                                             
    SET(BoldCyan    "${Esc}[1;36m")                                             
    SET(BOLDWHITE   "${Esc}[1;37m")                                             
ENDIF()

FUNCTION(message)                                                               
    LIST(GET ARGV 0 MessageType)                                                
    IF(MessageType STREQUAL FATAL_ERROR OR MessageType STREQUAL SEND_ERROR)        
        LIST(REMOVE_AT ARGV 0)                                                  
        _message(${MessageType} "${BoldRed}${ARGV}${ColourReset}")              
    ELSEIF(MessageType STREQUAL WARNING)                                        
        LIST(REMOVE_AT ARGV 0)                                                  
        _message(${MessageType}                                                 
        "${BoldYellow}${ARGV}${ColourReset}")                                   
    ELSEIF(MessageType STREQUAL AUTHOR_WARNING)                                 
        LIST(REMOVE_AT ARGV 0)                                                  
        _message(${MessageType} "${BoldCyan}${ARGV}${ColourReset}")             
    ELSEIF(MessageType STREQUAL STATUS)                                         
        LIST(REMOVE_AT ARGV 0)                                                  
        _message(${MessageType} "${Green}${ARGV}${ColourReset}")                
    ELSEIF(MessageType STREQUAL INFO)                                           
        LIST(REMOVE_AT ARGV 0)                                                  
        _message("${Blue}${ARGV}${ColourReset}")                                
    ELSE()                                                                      
        _message("${ARGV}")                                                     
    ENDIF()   
ENDFUNCTION()