<div align="center">
<h1><img src="Easy2D.png" width = "180" height = "180"/></h1>

**Easy2D 轻量级跨平台游戏开发框架**

</a>

[English](README_en-US.md) • [简体中文](README_zh-CN.md)

<a href="#安装">Install</a> •
<a href="#支持">Support</a> •
<a href="#许可">License</a>

</div>

Easy2D 是一门免费开源的轻量级游戏开发框架，由 RiCoCoSoul + Beanflame 主导移植开发工作。

期望在所有主流电脑平台（OSX、Windows 和 Linux）都能支持运行。


## 环境
- 平台
    - [x] Windows 
    - [ ] ~~Linux~~
    - [ ] ~~OSX~~
- 构建工具
    - [XMake仓库](https://gitee.com/ricocosoul_admin/easy2d)
      - [x] [XMake](https://xmake.io/#/zh-cn/)
    - [CMake仓库](https://gitee.com/ricocosoul_admin/easy2d/tree/CMake/)
      - [x] [CMake](https://cmake.org/)
- 代码编辑器
    - [x] [vscode](https://code.visualstudio.com/)
    - [x] [sublime](https://www.sublimetext.com/)
- 编译器 (支持i386和X86_64编译)
    - [x] [TDM GCC](https://jmeubank.github.io/tdm-gcc/download/)
    - [x] [MinGW GCC](https://github.com/brechtsanders/winlibs_mingw/releases)
    
## 安装

- 自定义编译
~~~html
    1、终端指定编译器
    xmake g --mingw=X:/MinGW 或者 X:/TDM-GCC

    2、切换编译器
    xmake f -p mingw --mingw=X:/MinGW -cvD 或者 X:/TDM-GCC
    如果全局指定可以使用xmake f --toolchain=mingw

    3、xmake

    4、done
~~~

- 远程包管理
~~~html
    <!-- 远程包加载 -->
    add_repositories("easy2d https://gitee.com/ricocosoul_admin/easy2d-repo")
    add_requires("easy2d")
    <!-- 项目 -->
    target("demo")
        <!-- 编译模式 -->
        set_kind("binary")
        <!-- 添加项目源文件 -->
        add_files("src/main.cpp")
        <!-- 添加包 -->
        add_packages("easy2d")
~~~

  
## 支持
- [XMake](https://xmake.io/#/zh-cn/)
- [Easy2D](https://easy2d.cn/)
## 许可
* [MIT License](./LICENSE)







