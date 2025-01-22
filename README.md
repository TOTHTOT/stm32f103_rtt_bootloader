<!--
 * @Author: TOTHTOT 37585883+TOTHTOT@users.noreply.github.com
 * @Date: 2025-01-09 22:54:57
 * @LastEditors: TOTHTOT 37585883+TOTHTOT@users.noreply.github.com
 * @LastEditTime: 2025-01-09 23:08:02
 * @FilePath: \stm32f103_rtt_temp\README.md
 * @Description:项目说明
-->
# stm32f103 模板工程

## 项目存放位置
 - 需要位于`rt_thread 根目录\bsp\stm32\stm32f103_rtt_temp`

## 使用方法
 - 使用`env`工具配置工程;
   - `menuconfig` 配置工程;
   - `scons --target=mdk5` 在配置完成后重新生成MDK5工程;
   - `pkgs --upgrade` 下载并更新所有包;

## 项目说明
 - 适用于`stm32f103`系列芯片;
 - 和rt thread 内核源码分离, 需要位于系统的`bsp`目录下;