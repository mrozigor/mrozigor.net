#!/bin/sh

versionFileName="src/version.hpp"
versionFileContent="#ifndef IM_APPLICATIONVERSION\n#define IM_APPLICATIONVERSION\n\n#include <string>\n\nnamespace im\n{\n\tclass ApplicationVersion\n\t{\n\tpublic:\n\t\tstatic std::string get()\n\t\t{\n\t\t\treturn \"%s\";\n\t\t}\n\t};\n}\n\n#endif"
versionFallback="0.x-unknown"

if [ -d .git ]; then
	printf "$versionFileContent" "$(git describe --dirty --always --tags)" > $versionFileName
else
	printf "$versionFileContent" "$versionFallback" > $versionFileName
fi
