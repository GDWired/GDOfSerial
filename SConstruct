#!python
import os
import platform
import sys
import subprocess

# For the reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

###############
## FUNCTIONS ##
###############

# Execute system 
def sys_exec(args):
    if platform.system() == "Windows":
        args.insert(0, "powershell.exe")
    proc = subprocess.Popen(args, stdout=subprocess.PIPE, text=True)
    (out, err) = proc.communicate()
    return out.rstrip("\r\n").lstrip()

# Compile using CMake
def compile(base_dir):
    if env["target"] == "debug":
        cmake_target = "Debug"
    else:
        cmake_target = "Release"
    
    sys_exec(["mkdir", "{}/{}".format(base_dir, env["target"])])
    if env["platform"] == "osx":
        sys_exec(["cmake", "-DDEMO=OFF", "-DSTATIC=ON", "-DCMAKE_OSX_ARCHITECTURES=arm64;x86_64", "-DCMAKE_BUILD_TYPE={}".format(cmake_target), "-B{}/{}".format(base_dir, env["target"]), "-S{}".format(base_dir)])
    elif env['platform'] == "windows":
        sys_exec(["cmake", "-DDEMO=OFF", "-DSTATIC=OFF", "-DCMAKE_BUILD_TYPE={}".format(cmake_target), "-B{}/{}".format(base_dir, env["target"]), "-S{}".format(base_dir)])
        sys_exec(["cmake", "--build", "{}/{}".format(base_dir, env["target"]), "--config", cmake_target])
        sys_exec(["cmake", "-DDEMO=OFF", "-DSTATIC=ON", "-DCMAKE_BUILD_TYPE={}".format(cmake_target), "-B{}/{}".format(base_dir, env["target"]), "-S{}".format(base_dir)])
    else:
        sys_exec(["cmake", "-DDEMO=OFF", "-DSTATIC=OFF", "-DCMAKE_BUILD_TYPE={}".format(cmake_target), "-B{}/{}".format(base_dir, env["target"]), "-S{}".format(base_dir)])
        
    sys_exec(["cmake", "--build", "{}/{}".format(base_dir, env["target"]), "--config", cmake_target])
    if env["platform"] == "windows":
        env.Append(LIBPATH=[env.Dir("{}/{}/{}/".format(base_dir, env["target"], cmake_target))])
    else:
        env.Append(LIBPATH=[env.Dir("{}/{}/".format(base_dir, env["target"]))])

env = SConscript("godot-cpp/SConstruct")

env.Append(CPPPATH=['src/'])
sources = Glob('src/*.cpp')

compile("ofSerial")

env.Append(CPPPATH=["{}/include".format("ofSerial")])
if env['platform'] == "osx":
    env.Append(LIBS=["libofserial.a"])
elif env['platform'] in ('x11', 'linux'):
    env.Append(LIBS=["libofserial.a"])
if env['platform'] == "windows":
    env.Append(LIBS=["ofserial.lib", "Setupapi.lib"])

# Create lib
sources = Glob("src/*.cpp")
library = env.SharedLibrary("demo/addons/GDOfSerial/{}/libgdofserial{}".format(env['platform'], env["SHLIBSUFFIX"]), source=sources)
Default(library)
