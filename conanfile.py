from conan import ConanFile
from conan.tools.cmake import CMakeDeps, CMakeToolchain


class BreakoutConan(ConanFile):
    name = "breakout"
    version = "1.0"

    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    requires = (
        "catch2/3.5.3",
        "imgui/1.92.6",
        "sdl/3.4.0",
        "fmt/12.1.0",
        "sfml/3.0.2",
        "nlohmann_json/3.11.3",
    )

    default_options = {
        "sdl2/*:shared": False,
        "fmt/*:shared": False,
        "sfml/*:window": True,
        "sfml/*:graphics": True,
    }