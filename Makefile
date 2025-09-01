
phony: all test

all:
	g++ source/*.cpp

TEST_FILE=test/test_vector.cpp

test: $(TEST_FILE)
	g++ $^ -I source