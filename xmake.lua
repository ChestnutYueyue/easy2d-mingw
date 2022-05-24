add_rules("mode.debug", "mode.release")

target("easy2d")
-- static   shared
set_kind("static")
-- add_cxflags("-mwindows")
-- add_cxflags("-fexec-charset=GBK")
-- add_cxflags("-finput-charset=utf-8")
-- add_cxflags("source-charset:utf-8")
add_includedirs("src/include")
add_headerfiles("src/include/easy2d/*.h", {
    prefixdir = "easy2d"
})
add_headerfiles("src/include/*.h", {
    prefixdir = ""
})

if is_host("windows")then
    if is_plat("mingw") then
        libdirs = {"libcomdlg32.a", "libd2d1.a", "libdinput.a", "libdinput8.a", "libdwrite.a", "libgdi32.a", "libimm32.a",
                "libmfplat.a", "libmfreadwrite.a", "libole32.a", "libshlwapi.a", "libwindowscodecs.a", "libwinmm.a","libxaudio2_8.a"}
        for i, v in ipairs(libdirs) do
            add_files("$(mingw)/x86_64-w64-mingw32/lib/" .. v)
        end
    end
end
add_files("src/source/**.cpp")

