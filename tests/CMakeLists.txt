add_executable(test_spin_mutex "test_spin_mutex.cpp")
add_executable(test_sleep_mutex "test_sleep_mutex.cpp")

target_link_libraries(test_spin_mutex spin_mutex)
target_link_libraries(test_sleep_mutex sleep_mutex)