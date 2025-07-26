@echo off
setlocal enabledelayedexpansion

:: 设置要清理的目录路径，这里使用当前目录，你可以修改为需要的路径
set "target_dir=W:\mycode\mb132github\gen"

echo 正在删除 %target_dir% 及其子目录下的 .mojom-module 和 .js 文件...
echo.

:: 删除 .mojom-module 文件
for /r "%target_dir%" %%f in (*.mojom-module) do (
    echo 删除: %%f
    del /f /q "%%f"
)

:: 删除 .js 文件
for /r "%target_dir%" %%f in (*.js) do (
    echo 删除: %%f
    del /f /q "%%f"
)

:: 删除 .info 文件
for /r "%target_dir%" %%f in (*.info) do (
    echo 删除: %%f
    del /f /q "%%f"
)

:: 删除 .pak 文件
for /r "%target_dir%" %%f in (*.pak) do (
    echo 删除: %%f
    del /f /q "%%f"
)

:: 删除 .rsp 文件
for /r "%target_dir%" %%f in (*.rsp) do (
    echo 删除: %%f
    del /f /q "%%f"
)

:: 删除 .ts_typemap_config 文件
for /r "%target_dir%" %%f in (*.ts_typemap_config) do (
    echo 删除: %%f
    del /f /q "%%f"
)

:: 删除 .zip 文件
for /r "%target_dir%" %%f in (*.zip) do (
    echo 删除: %%f
    del /f /q "%%f"
)

:: 删除 .validated 文件
for /r "%target_dir%" %%f in (*.validated) do (
    echo 删除: %%f
    del /f /q "%%f"
)

echo.
echo 文件删除完成。
pause