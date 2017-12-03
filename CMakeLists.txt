cmake_minimum_required(VERSION 2.6)

project(aresman)
set(aresman_VERSION_MAJOR 1)
set(aresman_VERSION_MINOR 0)
add_executable(aresman ./src/aresman.c)

project(daemonize)
set(daemonize_VERSION_MAJOR 1)
set(daemonize_VERSION_MINOR 0)
add_executable(daemonize ./spike/daemonize.c)

project(parse-args)
set(parse-args_VERSION_MAJOR 1)
set(parse-args_VERSION_MINOR 0)
add_executable(parse-args ./spike/parse-args.c)

project(processes)
set(processes_VERSION_MAJOR 1)
set(processes_VERSION_MINOR 0)
add_executable(processes ./spike/processes.c)

project(subprocess)
set(subprocess_VERSION_MAJOR 1)
set(subprocess_VERSION_MINOR 0)
set(CMAKE_C_FLAGS "-std=c99") 
add_executable(subprocess ./spike/subprocess.c)

project(sysconf)
set(sysconf_VERSION_MAJOR 1)
set(sysconf_VERSION_MINOR 0)
add_executable(sysconf ./spike/sysconf.c)

project(sysctl)
set(sysctl_VERSION_MAJOR 1)
set(sysctl_VERSION_MINOR 0)
add_executable(sysctl ./spike/sysctl.c)

