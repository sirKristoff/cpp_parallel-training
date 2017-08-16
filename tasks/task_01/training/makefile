
CPPFLAGS += 
CXXFLAGS += -g -Wall -Wextra -std=c++0x

RM := rm -rf


clean :
	$(RM) *.o $(TEST_TRGT)

%.o :  %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<
	
	
unit : mutex.o lockguard.o
	$(CXX)  $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $^
#-pthread