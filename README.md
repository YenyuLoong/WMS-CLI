# WMS-CLI（基于CLI的工资管理系统Demo）

**说实话，这个程序可以说设计得没有一点实用价值(～￣▽￣)～，这个程序的初衷是为了应付老同学的大学C语言课题设计（用的原生态的ASCII编码保存数据，无任何数据库结构），如果说这个项目有什么特点的话，除了古怪到爆的操作方式，还有一小部分算法还是值得参考的（笑）。**

**这是一个非常Stupid的基于CLI和ASCII数据文件的工资管理系统演示程序（Wages Management System Demo）（目前仅支持Windows操作系统）**

---

## 获取源代码
### Git版本控制工具：
* <code>git clone https://github.com/paslone/WMS-CLI.git</code>

### 下载zip压缩包：
* <a href="https://github.com/paslone/WMS-CLI/archive/master.zip">项目ZIP压缩包</a>

---

## 构建项目
### Windows操作系统（最好把MinGW中的bin目录添加到系统的PATH环境变量中）
1. 编译源代码
* 使用MinGW make自动构建：
  <p><code>mingw32-make -f Makefile.win</code></p>
* 使用MinGW GCC手动编译构建：
  <p><code>gcc -o wms.exe wms.c</code></p>

2. 添加Demo演示数据文件
*（这不是必要的，Demo演示数据文件中预先包含了一些演示用的员工数据，并且，程序运行时候若没有发现数据文件，会新建一个空的数据文件）*

* 使用MinGW make自动构建：
  <p><code>mingw32-make -f Makefile.win demofile</code></p>
* 手动复制：
  <p><code>copy employee.dat build\employee.dat</code></p>
