# XJTLU_Torpedo_Code
本仓库为飞镖控制代码

## 以下为飞镖操作手册

![](https://github.com/GMaster-TorpedoTeam/XJTLU_Torpedo_Code/raw/competition_mode/image/rc_image.jpg)

* (1) 启动前
  * S2拨到中间（刹车），S1随意

* (2) 手动模式（S2拨下）
  * 开启摩擦轮（S1拨上）<br>
  （之前代码有bug，这个功能用不了。更新后理论上来说应该能用）
  
  * pitch-yaw调节（S1拨中）<br>
    右摇杆前后控制pitch；<br>
    左摇杆左右控制yaw.
    
  * 飞镖推动板（S1拨下）<br>
    右摇杆往前，推进板前进；<br>
    右摇杆往后，推进板后退.
    
* (3) 比赛模式（S2拨上）<br>
  进入这个模式后，按键盘G或者遥控拨轮朝左拨进行发射.<br>
  （由于队里大部分遥控器的拨轮都是有问题的，可以通过宏定义rc_as_button（0/1）来快速（禁用/启用）遥控器控制发射）

* (4) 重置模式（S1，S2都拨中)<br>
  遥杆\/下内八 步进电机脉冲数归零，设为起始点（0，0）.<br>
  (步进电机的脉冲数会在OLED小屏上显示)


