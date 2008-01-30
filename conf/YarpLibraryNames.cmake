IF(YARP_HAS_MATH_LIB)
SET(YARP_LIBRARIES "${YARP_dev_LIB};${YARP_EXTMOD_LIBS};${YARP_dev_EXT_LIBS};${YARP_math_LIB};${YARP_sig_compat_LIB};${YARP_OS_compat_LIB};${YARP_sig_LIB};${YARP_OS_LIB};${ACE_LIB}")
SET(YARP_INCLUDES "${ACE_INCLUDE_DIR};${YARP_OS_INC};${YARP_sig_INC};${YARP_math_INC};${YARP_dev_INC};${YARP_OS_compat_INC}")
ELSE(YARP_HAS_MATH_LIB)
SET(YARP_LIBRARIES "${YARP_dev_LIB};${YARP_EXTMOD_LIBS};${YARP_dev_EXT_LIBS};${YARP_sig_compat_LIB};${YARP_OS_compat_LIB};${YARP_sig_LIB};${YARP_OS_LIB};${ACE_LIB}")
SET(YARP_INCLUDES "${ACE_INCLUDE_DIR};${YARP_OS_INC};${YARP_sig_INC};${YARP_dev_INC};${YARP_OS_compat_INC}")
ENDIF(YARP_HAS_MATH_LIB)
