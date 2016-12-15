 g++ -D _EMULATE_GLIBC=0  -isystem ../gtest-1.7.0-rc1/gtest-1.7.0/include  -I ../gtest-1.7.0-rc1/gtest-1.7.0  --std=gnu++11 test.cpp -o test.exe -L../gtest-1.7.0-rc1/gtest-1.7.0 -lgtest -lpthread 
  
 pause