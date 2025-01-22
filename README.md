<!--
 * @Author: TOTHTOT 37585883+TOTHTOT@users.noreply.github.com
 * @Date: 2025-01-09 22:54:57
 * @LastEditors: TOTHTOT 37585883+TOTHTOT@users.noreply.github.com
 * @LastEditTime: 2025-01-22 17:35:00
 * @FilePath: \stm32f103_rtt_temp\README.md
 * @Description:项目说明
-->
# stm32f103 qboot模板工程

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
 - 配置分区功能在`board\ports\fal_cfg.h`;
 - `RT_APP_PART_ADDR`位置要和`app`分区的一样;

## app 相关配置
 - 使能`ymodem`和`fal`;
 - 修改`board\linker_scripts\link.sct`脚本的下载位置, 参考如下, `0x0800b400`就是下载位置
```c
  LR_IROM1 0x0800b400 0x00040000  {    ; load region size_region
    ER_IROM1 0x0800b400 0x00040000  {  ; load address = execution address
    *.o (RESET, +First)
    *(InRoot$$Sections)
    .ANY (+RO)
    }
    RW_IRAM1 0x20000000 0x0000C000  {  ; RW data
    .ANY (+RW +ZI)
    }
  }
```
 - 修改app的中断向量
```c
static int ota_app_vtor_reconfig(void)
{
    #define NVIC_VTOR_MASK 0x3FFFFF80
    #define RT_APP_PART_ADDR 0x0800b400
    /* 根据应用设置向量表 */
    SCB->VTOR = RT_APP_PART_ADDR & NVIC_VTOR_MASK;

    return 0;
}
INIT_BOARD_EXPORT(ota_app_vtor_reconfig);
```
