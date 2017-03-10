# WMS-CLI（基于CLI的工资管理系统Demo）
## 说实话，这个程序可以说设计得没有一点实用价值(～￣▽￣)～，这个程序的初衷是为了应付同学的大学C语言课题设计（用的原生态的ASCII编码保存数据，无任何数据库结构），如果说这个项目有什么特点的话，古怪的操作方式，还有一部分算法还是值得参考的。
### 这是一个非常Stupid的基于CLI和ASCII数据文件的工资管理系统演示程序（Wages Management System Demo）（目前仅支持Windows操作系统）</p>

---

## 获取源代码
### 通过git：
* <code>git clone https://github.com/paslone/WMS-CLI.git</code>

### 下载zip包：
* <a href="https://github.com/paslone/WMS-CLI/archive/master.zip">项目ZIP包</a>

---

## 源代码编译
### 通过Windows上的MinGW（最好把MinGW中的bin目录添加到系统的PATH环境变量中）
* 使用MinGW make自动构建：
  <code>mingw32-make -f Makefile.win</code>
* 使用MinGW GCC手动编译构建：
  <code>gcc -o wms.exe wms.c</code>
