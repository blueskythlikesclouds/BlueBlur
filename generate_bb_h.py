import os

def generateIncludes(f, x):
    for (directoryPath, dirNames, fileNames) in os.walk(x):
        prefix = directoryPath[directoryPath.index(x):].replace("\\", "/")
    
        for fileName in fileNames:
            f.write("#include <{}/{}>\n".format(prefix, fileName))
     
    f.write("\n")
    
with open("BlueBlur.h", "w") as f:
    f.write("#pragma once\n\n")

    generateIncludes(f, "Hedgehog")
    generateIncludes(f, "Sonic")
    
    f.write(
"// Lost World/Forces style namespace aliases\n"\
"namespace hh = Hedgehog;\n"\
"namespace Hedgehog\n"\
"{\n"\
"    namespace base = Base;\n"\
"    namespace db = Database;\n"\
"    namespace fx = FxRenderFramework;\n"\
"    namespace math = Math;\n"\
"    namespace mr = Mirage;\n"\
"    namespace mot = Motion;\n"\
"    namespace fnd = Universe;\n"\
"    namespace ygg = Yggdrasill;\n"\
"}\n"\
"namespace app = Sonic;\n");