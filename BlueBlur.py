# This script must be run through Visual Studio or Developer Command Prompt.

import os

srcDirectoryPath = os.path.dirname(os.path.realpath(__file__))

asmFilePath = "\"" + srcDirectoryPath + "/BlueBlur.asm\""
objFilePath = "\"" + srcDirectoryPath + "/BlueBlur.obj\""
libFilePath = "\"" + srcDirectoryPath + "/BlueBlur.lib\""

os.system("ml /c /nologo /safeseh /Fo \"{}\" \"{}\"".format(objFilePath, asmFilePath))
os.system("lib /nologo /OUT:{} {}".format(libFilePath, objFilePath))

def generateIncludes(f, x):
    first = []
    second = []

    for (directoryPath, dirNames, fileNames) in os.walk(srcDirectoryPath + "/" + x):
        prefix = directoryPath[directoryPath.index(x):].replace("\\", "/")
    
        if "detail" in prefix:
            continue
    
        for fileName in fileNames:
            line = "#include <{}/{}>\n".format(prefix, fileName)
            if "Container" in prefix:
                if "hhMap" in fileName:
                    first.insert(0, line)
                else:
                    first.append(line)
            else:
                second.append(line)


    if first:
        f.write("#if (defined(_ITERATOR_DEBUG_LEVEL) && _ITERATOR_DEBUG_LEVEL != 0) || defined(_MAP_) || defined(_XTREE_)\n"\
"#if defined(_VECTOR_) || defined(_LIST_) || defined(_MAP_) || defined(_XTREE_)\n"\
"#error \"BlueBlur must be included before STL\"\n"\
"#endif\n"\
"#endif\n"\
"\n"\
"#pragma push_macro(\"_ITERATOR_DEBUG_LEVEL\")\n"\
"#undef _ITERATOR_DEBUG_LEVEL\n"\
"#define _ITERATOR_DEBUG_LEVEL 0\n\n")

        for line in first:
            f.write(line)

        f.write("\n#undef _ITERATOR_DEBUG_LEVEL\n")
        f.write("#pragma pop_macro(\"_ITERATOR_DEBUG_LEVEL\")\n\n")

    if second:
        for line in second:
            f.write(line)

        f.write("\n")
    
with open(srcDirectoryPath + "/BlueBlur.h", "w") as f:
    f.write("#pragma once\n\n")
    f.write("#pragma comment(lib, \"BlueBlur.lib\")\n\n")

    generateIncludes(f, "Hedgehog")
    generateIncludes(f, "CSD")
    generateIncludes(f, "Sonic")
    
    f.write(
"// Lost World/Forces style namespace aliases\n"\
"namespace hh = Hedgehog;\n"\
"namespace Hedgehog\n"\
"{\n"\
"    namespace anim = Animation;\n"\
"    namespace base = Base;\n"\
"    namespace db = Database;\n"\
"    namespace fx = FxRenderFramework;\n"\
"    namespace math = Math;\n"\
"    namespace mr = Mirage;\n"\
"    namespace mot = Motion;\n"\
"    namespace fnd = Universe;\n"\
"    namespace ygg = Yggdrasill;\n"\
"}\n\n"\
"namespace app = Sonic;\n")