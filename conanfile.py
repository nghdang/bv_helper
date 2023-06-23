from conans import ConanFile, CMake
import os

class BVHelper(ConanFile):
    name = "BV Helper"
    version = "0.0.1"
    generators = "cmake"
    settings = ["os", "arch", "compiler", "build_type"]
    if os.getenv("USERNAME") == "extnguyend":
        requires = "jsonformoderncpp/3.7.3@nlohmann/stable"
    else:
        requires = "nlohmann_json/3.11.2"
    export_sources = ["CMakeLists.txt", "*.cpp", "*.hpp", "*.h"]

    def build(self):
        cmake = CMake(self)
        cmake.generator = "Ninja"
        cmake.configure()
        cmake.build()
