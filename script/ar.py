import os
from pathlib import Path
from time import sleep
path1 = os.getcwd()
path = str(os.path.pardir)
mingw = Path(path, "bin")
lib = Path(mingw, "lib")
include = Path(mingw, "include")
if not os.path.exists(mingw):
    os.system(f"mkdir {mingw}")
    if not os.path.exists(lib):
        os.system(f"mkdir {lib}")
    if not os.path.exists(include):
        os.system(f"mkdir {include}")
for root, dirs, files in os.walk(path):
    for dirname in dirs:
        tempdir = Path(root, dirname)
        if Path(path, "src\include") == tempdir:
            os.system(f'Xcopy {tempdir} {include} /y/e/i/q')
    for file in files:
        if file.endswith(".a"):
            os.system(f'ar -x {Path(root, file)}')
os.remove(Path(path1, "libeasy2d.a"))
os.system(f'ar rc libeasy2d.a *.o *.obj')
sleep(1)
for file in os.listdir(path1):
    if file.endswith(".o") or file.endswith(".obj"):
        os.remove(Path(path1, file))
os.system(f'copy {Path(path1, "libeasy2d.a")} {lib}')
