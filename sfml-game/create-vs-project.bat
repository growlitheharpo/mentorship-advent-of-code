@echo off
pushd %~dp0
cd tools
premake5.exe vs2017
popd
