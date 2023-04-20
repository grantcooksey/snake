COMPONENT_NAME=display

SRC_FILES = \
  $(PROJECT_SRC_DIR)/display.c \

TEST_SRC_FILES = \
  $(UNITTEST_SRC_DIR)/test_display.c

include $(CPPUTEST_MAKFILE_INFRA)
