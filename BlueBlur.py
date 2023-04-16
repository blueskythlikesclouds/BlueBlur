# This script must be run through Visual Studio or Developer Command Prompt.

import os

srcDirectoryPath = os.path.dirname(os.path.realpath(__file__))

asmFilePath = "\"" + srcDirectoryPath + "/BlueBlur.asm\""
objFilePath = "\"" + srcDirectoryPath + "/BlueBlur.obj\""
libFilePath = "\"" + srcDirectoryPath + "/BlueBlur.lib\""

os.system("ml /c /nologo /safeseh /Fo \"{}\" \"{}\"".format(objFilePath, asmFilePath))
os.system("lib /nologo /OUT:{} {}".format(libFilePath, objFilePath))

def generateIncludes(f, x):
    for (directoryPath, dirNames, fileNames) in os.walk(srcDirectoryPath + "/" + x):
        prefix = directoryPath[directoryPath.index(x):].replace("\\", "/")
    
        if "detail" in prefix:
            continue
    
        for fileName in fileNames:
            f.write("#include <{}/{}>\n".format(prefix, fileName))

    f.write("\n")
    
with open(srcDirectoryPath + "/BlueBlur.h", "w") as f:
    f.write("#pragma once\n\n")
    f.write("#pragma comment(lib, \"BlueBlur.lib\")\n\n")

    generateIncludes(f, "Hedgehog")
    generateIncludes(f, "CSD")
    generateIncludes(f, "Sonic")
    
    f.write(
"#ifndef BB_EXCLUDE_NAMESPACE_ALIASES\n"\
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
"namespace app = Sonic;\n"\
"#endif")