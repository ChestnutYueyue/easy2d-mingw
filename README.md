<div align="center">
<h1><img src="Easy2D.png" width = "180" height = "180"/></h1>

**Easy2D 轻量级跨平台游戏开发框架**

</a>

[English](README_en-US.md) • [简体中文](README_zh-CN.md)

<a href="#安装">Install</a> •
<a href="#支持">Support</a> •
<a href="#许可">License</a>

</div>

Easy2D 是一门免费开源的轻量级游戏开发框架，由 ChestnutYueyue + Beanflame 主导移植开发工作。

期望在所有主流电脑平台（OSX、Windows 和 Linux）都能支持运行。

> 提示CMake没有提供合并库的工具需要借助python等其他脚本方式请先安装好python环境版本为3.8.10

## 环境
- 平台
    - [x] Windows 
    - [ ] ~~Linux~~
    - [ ] ~~OSX~~
- 构建工具
    - [XMake仓库](https://github.com/ChestnutYueyue/easy2d-mingw-xmake/)
      - [x] [XMake](https://xmake.io/#/zh-cn/)
    - [CMake仓库](https://github.com/ChestnutYueyue/easy2d-mingw-xmake/tree/cmake)
      - [x] [CMake](https://cmake.org/)
- 代码编辑器
    - [x] [vscode](https://code.visualstudio.com/)
    - [x] [sublime](https://www.sublimetext.com/)
- 编译器 (仅X64)
    - [x] [TDM GCC](https://jmeubank.github.io/tdm-gcc/download/)
    - [x] [MinGW GCC](https://github.com/brechtsanders/winlibs_mingw/releases)
## 安装


~~~make

    #1、安装

    #2、修改MinGW和CMake

    #3、在windows配置

    #4、修改MinGW和CMake的bin环境变量

    #5、修改MinGW bin目录下的mingw32-make.exe为make.exe

    #6、创建编译文件所在的build目录（可以是其他名称）

    #7、指定CMake产生Makefiles文件（说明，后面是两个点号指定cmake要编译上一层目录中的源码文件）：

        cmake -G "MinGW Makefiles" .
    
    #8、make

    #9、cmake会调用pyhon脚本生成库文件，到项目当前目录得bin文件夹中

    #10、从项目当前目录得bin文件夹复制到你的项目中请愉快的享用！

~~~


## 支持
- [CMake](https://cmake.org/)
- [Easy2D](https://easy2d.cn/)
## 许可
* [MIT License](./LICENSE)







