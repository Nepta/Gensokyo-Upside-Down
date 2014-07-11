premake.gcc.cxx = 'clang++'

solution "Template"
	configurations {"debug", "release"}
	buildoptions{"-std=c++11"}
	flags {"Unicode"}
	
	project "gensokyo-upside-down.out"
		kind "ConsoleApp"
		language "C++"

		files {"src/**.cpp"}
		excludes{"test*.c"}
		links {"sfml-graphics", "sfml-window", "sfml-system"}

--		linkoptions{"libjsmn.a"} --small linking hack

		configuration "release"
			flags {"OptimizeSpeed"}
--			buildoptions{"-O2"}

		configuration "debug"
			flags {"ExtraWarnings", "Symbols"}
			buildoptions{"-Wextra", "-O0"}
