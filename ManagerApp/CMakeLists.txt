install(FILES app_config.json DESTINATION /etc RENAME ServiceManagerConfig.json PERMISSIONS OWNER_WRITE OWNER_READ)

add_subdirectory(src)
add_subdirectory(tests)