#!/bin/bash

# 创建 debian 文件夹
mkdir -p debian

# 将上述文件复制到 debian 文件夹
cp -r debian/* debian/

# 生成 Debian 软件包
debuild -us -uc
